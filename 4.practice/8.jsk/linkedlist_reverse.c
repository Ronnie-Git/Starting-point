/*************************************************************************
	> File Name: linkedlist_reverse.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月12日 星期五 16时31分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    char data;
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

LinkNode *getNewNode(char value) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = value;
    p->next = NULL;
    return p;
}

void insert(LinkList *l, char value, int ind) {
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

void reverse(LinkList *l) {
    if (l->head.next == NULL) {
        return ;
    }
    LinkNode *next_node, *current_node;
    current_node = l->head.next;
    l->head.next = NULL;
    while (current_node != NULL) {
        next_node = current_node -> next;
        current_node -> next = l->head.next;
        l->head.next = current_node;
        current_node = next_node;
    }
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

void output(LinkList *l) {
    LinkNode *p = l->head.next;
    int i = 0;
    while (i < l->length) {
        if (i) printf(" ");
        printf("%c", p->data);
        p = p->next;
        i++;
    }
    printf("\n");
    return ;
}

int main() {
	LinkList *l = init();
    int n;
    scanf("%d", &n);
    char c;
    for (int i = 0, j = 0; i < 2 * n; i++) {
        scanf("%c", &c);
        if (c > 64) insert(l, c, j++);
    }
    reverse(l);
    output(l);
    clear(l);
    return 0;
}
