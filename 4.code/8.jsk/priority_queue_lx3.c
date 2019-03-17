/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月01日 星期四 19时23分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int p, d;
} Node;

typedef struct Heap {
    Node *data;
    int size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (Node *)malloc(sizeof(Node) * length_input);
    h->size = 0;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int p, int d) {
    h->data[h->size].p = p;
    h->data[h->size].d = d;
    int current = h->size;
    int father = (current - 1) / 2;
    while (h->data[current].p < h->data[father].p || (h->data[current].p == h->data[father].p && h->data[current].d < h->data[father].d)) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
}

Node top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
    int max_value = pos;
    if (lchild < n && (h->data[lchild].p < h->data[max_value].p || (h->data[lchild].p == h->data[max_value].p && h->data[lchild].d < h->data[max_value].d))) {
        max_value = lchild;
    }
    if (rchild < n && (h->data[rchild].p < h->data[max_value].p || (h->data[rchild].p == h->data[max_value].p && h->data[rchild].d < h->data[max_value].d))) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int heap_size(Heap *h) {
    return h->size;
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        int n, p, d;
        scanf("%d", &n);
        Heap *h = (Heap *)malloc(sizeof(Heap));
        init(h, n + 5);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p, &d);
            push(h, p, d);
        }
        int i = 1, ans = 0, a = 0, b = 0;
        while (h->size > 0) {
            a = top(h).p;
            b = top(h).d;
            ans = a;
            pop(h);
            if (i % 2 == 1) {
                push(h, a + b, b);
            }
            i++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
