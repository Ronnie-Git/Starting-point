/*************************************************************************
	> File Name: nwtxzyx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月12日 星期五 16时32分49秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    return p;
}

void insert(LinkList *l, int value, int ind) {
    LinkNode *p = &(l->head); // 虚拟节点
    while (ind--) {
        p = p->next;
        if (p == NULL) return ;
    }
    LinkNode *new_node = getNewNode(value);
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return ;
}

void erase(LinkList *l, int ind) {
    LinkNode *p = &(l->head);
    while (ind--) {
        p = p->next;
        if (p == NULL) return ;
    }
    if (p->next == NULL) return ;
    LinkNode *q = p->next;
    p->next = p->next->next;
    free(q);
    l->length -= 1;
    return ;
}

void clear(LinkList *l) {
    if (l->head.next == NULL) return ;
    LinkNode *p = l->head.next, *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

int main() {
    LinkList *l = init();
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        insert(l, i + 1, i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        erase(l, x - 1);
    }
    int k = (n - m) >> 1;
    LinkNode *p = &(l->head);
    for (int i = 0; i < k + 1; i++) {
        p = p->next;
    }
    printf("%d\n", p->data);
    clear(l);
    return 0;
}
