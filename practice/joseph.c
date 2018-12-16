/*************************************************************************
	> File Name: joseph.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月16日 星期日 17时17分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

Node *getNode(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        head->next = head;
        return head;
    }
    if (index == 0) {
        node->next = head->next;
        head->next = node;
        return head;
    }
    Node *p = head->next;
    int cnt = 0;
    while (p != head && cnt < index - 1) {
        p = p->next;
        cnt++;
    }
    if (cnt == index - 1) {
        node->next = p->next;
        p->next = node;
    }
    if (node == head->next) {
        head = node;
    }
    return head;
}

void output(LinkedList head, int m) {
    Node *p = head;
    head = NULL;
    while (p->next != p) {
        for (int i = 1; i < m; i++) {
            p = p->next;
        }
        printf("%d ", p->next->data);
        m = p->next->data;
        Node *delete_node = p->next;
        p->next = p->next->next;
        free(delete_node);
    }
    printf("%d\n", p->data);
    free(p);
}

int main() {
    LinkedList l = NULL;
    int n, m, value;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        Node *node = getNode(value);
        l = insert(l, node, i);
    }
    output(l, m);
    return 0;
}
