/*************************************************************************
	> File Name: linklist_two.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月12日 星期五 16时35分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
    struct LinkNode *prior;
} LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head.next = NULL;
    p->head.prior = NULL;
    p->length = 0;
    return p;
}

LinkNode *getNewNode(int value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    p->prior = NULL;
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
    if (p->next != NULL) p->next->prior = new_node;
    p->next = new_node;
    new_node->prior = p;
    l->length += 1;
    return ;
}

void clear(LinkList *l) {
    if (l->head.next == NULL) return ;
    LinkNode *p = l->head.next, *q;
    int i = 0;
    while (i < l->length) {
        q = p;
        p = p->next;
        free(q);
        i++;
    }
    free(l);
    return ;
}

void output(LinkList *l, int m) {
    LinkNode *p = l->head.next, *k = l->head.next;
    int i = 0;
    while (i < l->length - 1) {
        p = p->next;
        i++;
    }
    p->next = k;
    k->prior = p;
    i = 0;
    while (i < l->length - 1) {
        if (k->data == m) break;
        k = k->next;
        i++;
    }
    i = 0;
    while (i < l->length) {
        if (i) printf(" ");
        printf("%d", k->data);
        k = k->prior;
        i++;
    }
    printf("\n");
    return ;
}

int main() {
	LinkList *l = init();
    int n, x, m;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(l, x, i);
    }
    scanf("%d", &m); 
    output(l, m);
    clear(l);
    return 0;
}
