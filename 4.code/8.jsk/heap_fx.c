/*************************************************************************
	> File Name: heap_fx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月30日 星期二 17时49分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *data, size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (int *)malloc(sizeof(int) * length_input);
    h->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, int value) {
    h->data[h->size] = value;
    int cur = h->size;
    int f = (cur - 1) / 2;
    while (h->data[cur] > h->data[f]) {
        swap(&h->data[cur], &h->data[f]);
        cur = f;
        f = (cur - 1) / 2;
    }
    h->size++;
    return ;
}

void output(Heap *h) {
    for (int i = 0; i < h->size; i++) {
        //i && printf(" ");
        printf("%d ", h->data[i]);
    }
    printf("\n");
    return ;
}

int top(Heap *h) {
    return h->data[0];
}

void update(Heap *h, int pos, int n) {
    int l = 2 * pos + 1, r = 2 * pos + 2;
    int max = pos;
    l < n && (max = (h->data[l] > h->data[max] ? l : max));
    r < n && (max = (h->data[r] > h->data[max] ? r : max));
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

void heap_sort(Heap *h) {
    for (int i = h->size - 1; i >= 1; i--) {
        swap(&h->data[i], &h->data[0]);
        update(h, 0, i);
    }
}

void clear(Heap *h) {
    free(h->data);
    free(h);
    return ;
}

int main() {
    int n, a, m;
    Heap *h = (Heap *)malloc(sizeof(Heap));
    scanf("%d", &n);
    init(h, n + 5);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(h, a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("%d\n", top(h));
        pop(h);
    }
    output(h);
    heap_sort(h);
    output(h);
    clear(h);
    return 0;
}
