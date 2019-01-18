/*************************************************************************
	> File Name: xxb_expand.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月10日 星期一 17时04分34秒
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
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
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

int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 100);
    printf("%d\n", insert(a, 1, 0));
    clear(a);
    return 0;
}
