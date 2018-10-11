/*************************************************************************
	> File Name: vector.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月11日 星期四 18时56分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//实现init()默认参数
#define DEFAULT_ARG(a, b) ((#a)[0] ? a + 0 : b)
#define init(a) __init(DEFAULT_ARG(a, 10))

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *__init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->length = 0;
    return p;
}

int expand(Vector *v) {
    //printf("[%p] expanding\n", v->data);
    int *p = (int *)realloc(v->data, sizeof(int) * 2 * v->size); // 重新申请内存空间
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    //printf("[%p] expand vector success, the new size : %d\n", v->data, v->size);
    return 1;
}

int insert(Vector *v, int value, int ind) {
    if (v->length == v->size) {
        if (expand(v) == 0) {
            return 0;
        }
    }
    if (ind < 0 || ind > v->length) return 0;
    for (int i = v->length - 1; i >= ind; --i) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = value;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    if (v->length == 0) return 0;
    if (ind < 0 || ind > v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

void output(Vector *v) {
    printf("Vector = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    Vector *v = init();
    #define MAX_op 40
    for (int i = 0; i < MAX_op; i++) {
        int op = rand() % 5, ind, value;
        switch (op) {
            case 2:
            case 3:
            case 4:
            case 0: {
                ind = rand() % (v->length + 3) - 1;
                value = rand() % 100;
                printf("[%d] insert(%d, %d) to vector\n", insert(v, value, ind), value, ind);
                output(v);
            } break;
            case 1: {
                ind = rand() % (v->length + 3) - 1;
                printf("[%d] erase(%d) from vector\n", erase(v, ind), ind);
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}
