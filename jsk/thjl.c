/*************************************************************************
	> File Name: thjl.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月17日 星期三 18时01分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

typedef struct Q {
    LL *data;
    int h, t, len;
} Q;

void init(Q *q, int len) {
    q->data = (LL *)malloc(sizeof(LL ) * len);
    q->len = len;
    q->h = 0;
    q->t = -1;
}

void push(Q *q, LL x) {
    q->t++;
    q->data[q->t] = x;
}

void put(Q *q1, Q *q2, Q *q3) {
    for (int i = 0; i < 10; i++) {
        printf("%lld %lld %lld\n", q1->data[i], q2->data[i], q3->data[i]);
    }
    return ;
}

void clear(Q *q) {
    free(q->data);
    free(q);
}

int main() {
    LL num, x;
    Q *q1 = (Q *)malloc(sizeof(Q));
    Q *q2 = (Q *)malloc(sizeof(Q));
    Q *q3 = (Q *)malloc(sizeof(Q));
    init(q1, 20);
    init(q2, 20);
    init(q3, 20);
    for (int i = 0; i < 10; i++) {
        scanf("%lld %lld", &num, &x);
        switch(num) {
            case 0: push(q1, x); break;
            case 1: push(q2, x); break;
            case 2: push(q3, x); break;
        }    
    }
    put(q1, q2, q3);
    clear(q1);
    clear(q2);
    clear(q3);
}
