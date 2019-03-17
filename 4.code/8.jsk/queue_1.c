/*************************************************************************
	> File Name: queue_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月11日 星期四 17时53分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue{
    int *data;
    int head, tail, length;
}Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if (q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}
void output(Queue *q) {
    for (int i = q->head; i <= q->tail; i++) {
        if (i != q->head) printf(" ");
        printf("%d", q->data[i]);
    }
    printf("\n");
}
int front(Queue *q) {
    return q->data[q->head];
}
void pop(Queue *q) {
    q->head++;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    int m, n;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        push(queue, n);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop(queue);
    }
    printf("%d\n", front(queue));
    output(queue);
    clear(queue);
    return 0;
}

