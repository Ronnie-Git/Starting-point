/*************************************************************************
	> File Name: vector_letf.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月12日 星期五 16时27分03秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int length;
    int *data;
} node;

void init(node *a, int n, int m) {
    a->length = 0;
    a->data = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a->data[i]);
        a->length++;
    }
    return ;
}

void left(node *a, int k) {
    int *p = (int *)malloc(sizeof(int) * (a->length + 5));
    for (int i = 0; i < k; i++) {
        p[i] = a->data[i];
    }
    for (int i = 0; i < a->length - k; i++) {
        a->data[i] = a->data[i + k];
    }
    for (int i = a->length - k; i < a->length; i++) {
        a->data[i] = p[i + k - a->length];
    }
    free(p);
    return ;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    node *a = (node *)malloc(sizeof(node));
    init(a, n + 10, n);
    left(a, k);
    for (int i = 0; i < a->length - 1; i++) {
        printf("%d ", a->data[i]);
    }
    printf("%d\n", a->data[a->length - 1]);
    free(a);    
    return 0;
}
