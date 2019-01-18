/*************************************************************************
	> File Name: p1304.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月21日 星期五 17时42分51秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 10000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init() {
    is_prime[0] = is_prime[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2) {
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] >= i) break;
            if (!is_prime[i - prime[j]]) {
                printf("%d=%d+%d\n", i, prime[j], i - prime[j]);
                break;
            }
        }
    }
    return 0;
}
