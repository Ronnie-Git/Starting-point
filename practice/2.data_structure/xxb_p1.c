/*************************************************************************
	> File Name: xxb_p1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月10日 星期一 18时00分48秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector -> size = size;
    vector -> length = 0;
    vector -> data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
	int *old_data = vector -> data;
    vector -> size = vector -> size * 2;
    vector -> data = (int *)malloc(sizeof(int) * vector -> size);
    for (int i = 0; i < vector -> length; i++) {
        vector -> data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int v) {
	if (loc < 0 || loc > vector -> length) return 0;
    if (vector -> length >= vector -> size) {
        expand(vector);
        printf("expand\n");
    }
    for (int i = vector -> length; i > loc; i--) {
        vector -> data[i] = vector -> data[i - 1];
    }
    vector -> data[loc] = v;
    vector -> length++;
    return 1;
}


void clear(Vector *vector) {
	free(vector -> data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
	int n, p, q;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &p, &q);
        int ans = insert(a, p, q);
        if (ans == 0) {
            printf("failed\n");
        } else if (ans == 1) {
            printf("success\n");
        } else {
            printf("expand\n");
        }
    }
    return 0;
}
