/*************************************************************************
	> File Name: tree_lx2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月24日 星期三 20时49分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = ch;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *build(char *str, Node *root, int init) {
    if (str[0] == 0) return NULL;
    static int i;
    if (init == 1) i = 0;
    Node *p = NULL; int flag = 0;
    while (str[i]) {
        switch (str[i]) {
            case '(' : {
                i += 1;
                p = build(str, p, 0);
            } break;
            case ')' : {
                if (root == NULL) return p;
                return root;
            } break;
            case ',' : {
                flag = 1;
            } break;
            case ' ' : {
            } break;
            default : {
                p = getNewNode(str[i]);
                if (root != NULL) {
                    if (flag == 0) root->lchild = p;
                    else root->rchild = p;
                }
            } break;
        }
        i += 1;
    }
    return (root ? root : p);
}

void del(Node *root, char x) {
    if (root == NULL) return ;
    if (root->lchild && root->lchild->key == x) {
        root->lchild = NULL;
        return ;
    }
    if (root->rchild && root->rchild->key == x) {
        root->rchild = NULL;
        return ;
    }
    del(root->lchild, x);
    del(root->rchild, x);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    printf("%c", root->key);
    if (root->lchild || root->rchild) {
        printf("(");
        output(root->lchild);
    } else {
        return ;
    }
    if (root->rchild != NULL) printf(",");
    output(root->rchild);
    printf(")");
    return ;
}

int main() {
    char str[1000], x;
    scanf("%[^\n]s", str);
    getchar();
    scanf("%c", &x);
    int k = strlen(str);
    Node *p = build(str, NULL, 1);
    if (!k || p->key == x) {
        printf("\n");
        return 0;
    }
    del(p, x);
    output(p);
    printf("\n");
    return 0;
}
