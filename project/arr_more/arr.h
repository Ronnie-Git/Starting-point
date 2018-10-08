/*************************************************************************
	> File Name: arr.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月05日 星期五 15时03分51秒
 ************************************************************************/

#ifndef _ARR_H
#define _ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000000

struct arr{
    int type;
    union {
        double n1;
        float n2;
        int n3;
        char n4;
        long long int n5;
    } num;
}a[MAX_N + 5];

void print(arr *n) {
    switch (n->type) {
        case 1: printf("%.14lf ", n->num.n1); break;
        case 2: printf("%f ", n->num.n2); break;
        case 3: printf("%d ", n->num.n3); break;
        case 4: printf("%c ", n->num.n4); break;
        case 5: printf("%lld ", n->num.n5); break;
    }
}

void set(arr *n, double num) {
	n->type = 1;
	n->num.n1 = num;
    //printf("%lf\n", n->num.n1);
}

void set(arr *n, float num) {
	n->type = 2;
	n->num.n2 = num;
    //printf("%f\n", n->num.n2);
}

void set(arr *n, int num) {
	n->type = 3;
	n->num.n3 = num;
    //printf("%d\n", n->num.n3);
}

void set(arr *n, char num) {
	n->type = 4;
	n->num.n4 = num;
    //printf("jbxsj%c\n", n->num.n4);
}

void set(arr *n, long long int num) {
	n->type = 5;
	n->num.n5 = num;
    //printf("%lld\n", n->num.n5);
}

void rand_num(int m) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        int n = rand() % 4 + 1;
        switch (n) {
            case 1: set(a + i, ((double)(rand() % 10000000)) / 10000000.0 * 100.0); break;
            case 2: set(a + i, ((float)(rand() % 10000000)) / 10000000.0 * 100.0); break;
            case 3: set(a + i, rand() % 10000); break;
            case 4: {
                char value = rand() % 10 + '0';
                set(a + i, value);
            } break;
            case 5: set(a + i, rand() % 100000000); break;
        }
    }
}

void scanf_num(int m) {
    for (int i = 0; i < m; i++) {
        int n;
        printf("请选择:\n1.double 2.float 3.int 4.char 5.long long int\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                double value;
                printf("请输入double类型：");
                scanf("%lf", &value);
                set(a + i, value);
            } break;
            case 2: {
                float value;
                printf("请输入float类型：");
                scanf("%f", &value);
                set(a + i, value);
            } break;
            case 3: {
                int value;
                printf("请输入int类型：");
                scanf("%d", &value);
                set(a + i, value);
            } break;
            case 4: {
                char value, l;
                printf("请输入char类型：");
                scanf("%c%c", &l, &value);
                set(a + i, value);
            } break;
            case 5: {
                long long int value;
                printf("请输入long long int类型：");
                scanf("%lld", &value);
                set(a + i, value);
            } break;
        }
    }
}

#endif
