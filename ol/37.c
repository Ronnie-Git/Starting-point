/*************************************************************************
	> File Name: 37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 14时18分22秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_N 1000000

int is_prime[MAX_N + 5] = {0};//标记素数
int prime[MAX_N + 5] = {0};//储存素数

void init() {//线性筛
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int left(int x) {//左删
    while (x) {
        if (is_prime[x]) return 0;
        x %= (int)pow(10, floor(log10(x)));
    }
    return 1;
}

int right(int x) {//右删
    while (x) {
        if (is_prime[x]) return 0;
        x /= 10;
    }
    return 1;	
}

int main() {
    init();
    is_prime[0] = 1, is_prime[1] = 1;
    int ans = 0;
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (left(prime[i]) && right(prime[i])) ans += prime[i];
    }
    printf("%d\n", ans);
    return 0;
}
