/*************************************************************************
	> File Name: p1115.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月05日 星期三 19时47分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int size, head, tail;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = n;
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = 0;
    q->tail = -1;
    return q;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void push(Queue *q, int val) {
    if (q->tail + 1 >= q->size) return ;
    q->tail += 1;
    q->data[q->tail] = val;
    return ;
}

void pop(Queue *q) {
    if (empty(q) || q->head >= q->size) return ;
    q->head += 1;
    return ;
}

int front(Queue *q) {
    return q->data[q->head];
}

void output(Queue *q) {
    if (empty(q)) return ;
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int n, max, m, sum = 0;
    scanf("%d", &n);
    Queue *q = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        push(q, m);
        sum += m;
        if (!i) max = m;
        if (sum > max) max = sum;
        while (sum < 0 && !empty(q)) {
            sum -= front(q);
            pop(q);
        }
        if (sum > max && !empty(q)) max = sum;
    }
    printf("%d\n", max);
    return 0;
}
