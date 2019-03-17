/*************************************************************************
	> File Name: tree_lx1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月24日 星期三 18时59分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node* init(char data) {
    Node *node =(Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void postorder(Node *node) {
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%c", node->data);
}

void postorder_2(Node *node) {
    if (node->rchild != NULL) {
        postorder_2(node->rchild);
    }
    if (node->lchild != NULL) {
        postorder_2(node->lchild);
    }
    printf("%c", node->data);
}

Node *build(char pre_str[], char in_str[], int len) {
    Node *p = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}

void clear(Node *node) {
    if (node->lchild != NULL) {
        clear(node->lchild);
    }
    if (node->rchild != NULL) {
        clear(node->rchild);
    }
    free(node);
}

int main() {
    char pre_str[100], in_str[100];
    scanf("%s %s", pre_str, in_str);
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder(root);
    printf("\n");
    postorder_2(root);
    printf("\n");
    clear(root);
    return 0;
}
