/*************************************************************************
	> File Name: 47.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 12时21分10秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100000000

int prime[MAX_N + 5] = {0};

void init(){
    for (int i = 2; i * i <= MAX_N; i++) { // 素数筛
        if (prime[i]) continue;
        for (int j = 2 * i; j * i <= MAX_N; j += i) prime[j]++; // 计算素因子数
    }
}

int main() {
    init();
    int k = 0;
    for (int i = 2; i <= MAX_N; i++) { // 查找一组连续四个数都有四个不同的素因子数 输出第一个数
        if (prime[i] == 4) k++;
        else k = 0;
        if (k == 4) {
            printf("%d\n", i - 3);
            break;
        }
    }
    return 0;
}
