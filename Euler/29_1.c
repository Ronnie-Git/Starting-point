/*************************************************************************
	> File Name: 29_1.c
	> Author:
	> Mail: 
	> Created Time: 2018年07月31日 星期二 11时12分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000
#define MAX_M 210

int *result[MAX_N] = {0};
int result_length = 0;

int find_result(int *num) {
    for (int i = 0; i < result_length; i++) {
        if (memcmp(result[i], num, sizeof(int) * MAX_M)) continue; // 内存比较
        return i + 1;
    }
    return 0;
}

int* calc_num(int a, int b) {
    //temp[MAX_M] = {0};
    int* temp = (int *)calloc(sizeof(int), MAX_M);
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a; // 大数乘法
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main() {
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            int *temp = calc_num(a, b); // 同类型
            if (!find_result(temp)) result[result_length++] = temp;
            else free(temp);
        }
    }
    printf("%d\n", result_length);
    return 0;
}
