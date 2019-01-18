/*************************************************************************
	> File Name: 39.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 18时14分09秒
 ************************************************************************/
#include <stdio.h>

#define MAX_N 250000
#define MAX_M 500

int c[MAX_N] = {0}; // 储存平方数
int p_length[1005] = {0}; // 储存直角三角形个数

int main() {
    int length = 0, ans = 0;
    for (int i = 1; i < MAX_M; i++) c[i * i] = i; // 平方数
    for (int i = 1; i < MAX_M; i++) {
        for (int j = i + 1; j < MAX_M; j++) {
            int x = i * i + j * j; // x = a * a + b * b 边长 a, b
            if (x >= MAX_N || !c[x] || i + j + c[x] > 1000) continue; // 判断 边长c 是否存在  
            int p = i + j + c[x]; // 周长
            if (++p_length[p] > length) {
                length = p_length[p];
                ans = p;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
