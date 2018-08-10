/*************************************************************************
	> File Name: 50.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 18时10分36秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) { // 线性筛
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    init();
    int sum = 0, ans = 0, len = 0, ans_len = 0;
    for (int i = 1; i <= prime[0]; i++) { // 求小于1000000最长的可以写成连续素数和的素数
        len = 0;
        sum = 0;
        for (int j = i; j <= prime[0]; j++) {
            sum += prime[j];
            len++;
            if (sum >= MAX_N) break;
            if (is_prime[sum]) continue;
            if (len > ans_len) {
                ans_len = len;
                ans = sum;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
