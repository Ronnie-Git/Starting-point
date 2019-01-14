/*************************************************************************
	> File Name: queue.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月21日 星期日 18时35分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = 0;
    q->tail = -1;
    q->cnt = 0;
    return q;
}

int push(Queue *q, int value) {
    if (q->cnt == q->length) return 0;
    q->tail += 1;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = value;
    return 1;
}

int empty(Queue *q) {
    return q->cnt == 0;
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

int front(Queue *q) {
    if (empty(q)) return 0;
    return q->data[q->head];
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Queue *q = init(n + 5);
        for (int i = n; i >= 1; i--) {
            push(q, i);
            int cnt = i;
            while (cnt--) {
                int temp = front(q);
                pop(q);
                push(q, temp);
            }
        }
        int num[15] = {0}, ind = 0;
        while (!empty(q)) {
            num[ind++] = front(q);
            pop(q);
        }
        for (int i = ind - 1; i >= 0; i--) {
            if (i != ind - 1) cout << " ";
            cout << num[i];
        }
        cout << endl;
        clear(q);
    }
    return 0;
}
