/*************************************************************************
	> File Name: AVL.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月25日 星期五 15时37分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ({ \
    __typeof(a) __a = (a); \
    __typeof(b) __b = (b); \
    __a > __b ? __a : __b; \
})

typedef struct Node {
    int key;
    int height;
    struct Node *lchild, *rchild;
} Node;

// 虚拟结点
Node *NIL = NULL;

Node *init(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->height = 1;
    // 将新申请的结点的左右孩子都指向虚拟节点，方便比较高
    p->lchild = p->rchild = NIL;
    return p;
}

// 初始化虚拟节点 先于主函数执行
__attribute__((constructor))
void init_NIL() {
    NIL = init(0);
    NIL->height = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

// 更新当前结点的高度
void calc_height(Node *root) {
    root->height = max(root->lchild->height, root->rchild->height) + 1;
    return ;
}

// 左旋
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

// 右旋
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

// 调整平衡
Node *maintain(Node *root) {
    if (abs(root->lchild->height - root->rchild->height) <= 1) return root;
    if (root->lchild->height > root->rchild->height) {
        if (root->lchild->lchild->height < root->lchild->rchild->height) { // LR
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->rchild->height < root->rchild->lchild->height) { // RL
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    else if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    calc_height(root);
    return maintain(root);
}

// 找到到当前结点左子树中最大的节点
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else {
        if (root->lchild == NIL && root->rchild == NIL) {
            free(root);
            return NIL;
        } else if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild != NIL ? root->lchild : root->rchild);
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root); 
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    calc_height(root);
    return maintain(root);
}

void clear(Node *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n", root->key, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (scanf("%d%d", &op, &val) != EOF) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
    }
    return 0;
}
