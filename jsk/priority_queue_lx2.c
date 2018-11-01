/*************************************************************************
	> File Name: priority_queue_lx2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月01日 星期四 16时54分51秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int a, c;
} Node;

typedef struct Heap {
    Node *data;
    int size;
} Heap;

void init(Heap **h, int length_input) {
    for (int i = 0; i < 102; i++) {
        h[i] = (Heap *)malloc(sizeof(Heap));
        h[i]->data = (Node *)malloc(sizeof(Node) * length_input);
        h[i]->size = 0;
    }
    return ;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int a, int c) {
    h->data[h->size].a = a;
    h->data[h->size].c = c;
    int cur = h->size;
    int f = (cur - 1) / 2;
    while (h->data[cur].a > h->data[f].a) {
        swap(&h->data[cur], &h->data[f]);
        cur = f;
        f = (cur - 1) / 2;
    }
    h->size++;
    return ;
}

void update(Heap *h, int pos, int n) {
    int l = 2 * pos + 1, r = 2 * pos + 2;
    int max = pos;
    l < n && (max = (h->data[l].a > h->data[max].a ? l : max));
    l < n && (max = ((h->data[l].a == h->data[max].a && h->data[l].c < h->data[max].c)? l : max));
    r < n && (max = (h->data[r].a > h->data[max].a ? r : max));
    r < n && (max = ((h->data[r].a == h->data[max].a && h->data[r].c < h->data[max].c)? r : max));
    if (max != pos) {
        swap(&h->data[pos], &h->data[max]);
        update(h, max, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

void func() {
    int n, f, s;
    scanf("%d", &n);
    Heap *h[105];
    init(h, n + 5);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &f, &s);
        push(h[s], f, i);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int max = 0, num = 0;
        for (int j = 0; j < 101; j++) {
            if (!h[j]->size) continue;
            int temp = h[j]->data[0].a + i * j;
            if (temp > max || (temp == max && h[j]->data[0].c < h[num]->data[0].c)) {
                max = temp;
                num = j;
            }
        }
        flag && printf(" ");
        printf("%d", h[num]->data[0].c);
        pop(h[num]);
        flag = 1;
    }
    printf("\n");
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        printf("Case #%d:\n", k);
        func();
    }
    return 0;
}
