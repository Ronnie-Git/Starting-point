/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月31日 星期三 16时34分44秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Heap {
    double *data;
    int size;
} Heap;

void init(Heap *h, int length_input) {
    h->data = (double *)malloc(sizeof(double) * length_input);
    h->size = 0;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *h, double value) {
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

double top(Heap *h) {
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
    int n;
    double temp, x;
    scanf("%d", &n);
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h, n + 5);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        push(h, x);
    }
    while (h->size > 1) {
        double a = top(h);
        pop(h);
        double b = top(h);
        pop(h);
        temp = pow(a * b * b, 1.0 / 3.0);
        push(h, temp);
    }
    printf("%.12lf\n", top(h));
    clear(h);
    return 0;
}
