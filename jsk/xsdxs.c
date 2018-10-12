/*************************************************************************
	> File Name: xsdxs.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月12日 星期五 16时27分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vector {
    int length, x;
    int *n, *m;
} Vector;

void init(Vector *a, int s, int k) {
    a->length = 0;
    a->n = (int *)malloc(sizeof(int) * s);
    a->m = (int *)malloc(sizeof(int) * s);
	for (int i = 0; i < k; i++) {
        scanf("%d %d", &a->n[i], &a->m[i]);
    	a->length++;
    }
    scanf("%d", &a->x);
    return ;
}

int func(Vector *a) {
    int ans = 0;
    for (int i = 0; i < a->length; i++) {
        ans += a->n[i] * (int)pow(a->x, a->m[i]);
    }
    return ans;
}

int main() {
    int k, x;
    Vector *a = (Vector *)malloc(sizeof(Vector));
    scanf("%d", &k);
    init(a, k + 10, k);
    printf("%d\n", func(a));
	return 0;
}
