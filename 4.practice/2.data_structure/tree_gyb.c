/*************************************************************************
	> File Name: tree_gyb.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月24日 星期三 18时54分34秒
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

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%c ", root->key);
    output(root->rchild);
    return ;
}

int main() {
    char str[1000];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("read = %s\n", str);
        Node *p = build(str, NULL, 1);
        output(p); printf("\n");
    }
    return 0;
}
