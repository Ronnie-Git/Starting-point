/*************************************************************************
	> File Name: RBT.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月17日 星期日 19时27分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef int color_t;

typedef struct RBTNode {
    int key;
    color_t color; // 0 red, 1 black, 2 double black
    struct RBTNode *lchild, *rchild;
} RBTNode;

// 虚拟节点
RBTNode *NIL;

// 在主函数执行前初始化 NIL
__attribute__((constructor))
void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->key = -1;
    NIL->color = BLACK; // NIL颜色初始化为黑色
    NIL->rchild = NIL->lchild = NIL;
    return ;
}

RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
    p->key = key;
    p->lchild = p->rchild = NIL; // 新的节点左右孩子都指向NIL
    p->color = RED; // 新的节点都初始化红色
    return p;
}

// 判断孩子中是否有红色
int has_red_child(RBTNode *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

// 左旋
RBTNode *left_rotate(RBTNode *node) {
    RBTNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

// 右旋
RBTNode *right_rotate(RBTNode *node) {
    RBTNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

/* 插入调整，从祖父节点看，主要是去掉两个连续红色节点
 * x 是红色有三种情况
 * 1. x 的父节点是红色，叔父节点是红色
 * 2. x 的父节点是红色，叔父节点是黑色，x 是一个左孩子
 * 3. x 的父节点是红色，叔父节点是黑色，x 是一个右孩子
 */
RBTNode *insert_maintain(RBTNode *root) {
    if (!has_red_child(root)) return root; // x 的父亲和叔父都不是红色
    if (root->lchild->color == RED && root->rchild->color == RED) { // x的父亲和叔父都是红色
        // 可以去掉下行代码 因为最后红色上顶都不会使红黑树出错
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
    } else if (root->lchild->color == RED && has_red_child(root->lchild)) { // LL LR
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->rchild->color == RED && has_red_child(root->rchild)) { // RR RL
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    } else {
        return root;
    }
	// 红色上顶
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    else if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

// 因为根节点可能会变成双重黑或改变 所以需在__insert函数外在写一层insert函数
RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key); // 根节点可能会改变
    root->color = BLACK; // 避免根节点双重黑
    return root;
}

// 找前驱
RBTNode *predecessor(RBTNode *root) {
    RBTNode *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

/* 删除调整，从父节点看，主要是去掉双重黑
 * x 是双重黑有四种情况
 * 1. x 的兄弟节点是黑色，兄弟节点的孩子节点都是黑色
 * 2. x 的兄弟节点是黑色，兄弟节点左孩子是红色，右孩子是黑色
 * 3. x 的兄弟节点是黑色，兄弟节点右孩子是红色（左孩子红黑都可）
 * 4. x 的兄弟节点是红色
 */
RBTNode *erase_maintain(RBTNode *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root; // 左右孩子都不是双重黑
    // x 是双重黑，兄弟是黑色，兄弟节点的孩子节点都是黑色
    #define UNBALANCE(a, b) (root->a->color == DOUBLE_BLACK && root->b->color == BLACK && !has_red_child(root->b))
    if (UNBALANCE(lchild, rchild) || UNBALANCE(rchild, lchild)) {
        // x 去掉双重黑， x 的父节点加一重黑
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    #undef UNBALANCE
    // x 是双重黑，兄弟节点的孩子节点有红色的
    if (root->lchild->color == DOUBLE_BLACK) {
        if (root->rchild->color == RED) { // 兄弟节点是红色，将其变成黑色，再递归调整
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        root->lchild->color = BLACK; // 去掉双重黑
        if (root->rchild->rchild->color != RED) { // RL
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        root = left_rotate(root);
        root->color = root->lchild->color; // 新的根节点的颜色变为原来根节点的颜色
    } else {
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        root->rchild->color = BLACK; // 去掉双重黑
        if (root->lchild->lchild->color != RED) { // LR
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = BLACK; // 根节点左右孩子都变为黑色
    return root;
}

RBTNode *__erase(RBTNode *root, int key) {
    if (root == NIL) return NIL;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) { // 节点出度为 1 或 0
            RBTNode *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else { // 节点出度为 2
            RBTNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

RBTNode *erase(RBTNode *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(RBTNode *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void output(RBTNode *root) {
    if (root == NIL) return ;
    printf("(%d %d %d) = %d\n", root->key, root->lchild->key, root->rchild->key, root->color);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    int op, val;
    RBTNode *root = NIL;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 5, val = rand() % 10;
        switch (op) {
            case 0: 
                printf("delete val %d from RBT\n", val);
                root = erase(root, val);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("insert val %d to RBT\n", val);
                root = insert(root, val);
                break;
        }
        output(root);
    }
    clear(root);
    return 0;
}
