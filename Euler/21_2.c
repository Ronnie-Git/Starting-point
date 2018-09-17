/*************************************************************************
	> File Name: p1851_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月15日 星期六 18时36分12秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100000

int is_prime[MAX_N + 5] = {0};
int prime[MAX_N] = {0};
int num[MAX_N + 5]  = {0};
 
void init() {
    num[1] = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) { 
            is_prime[i] = i;
            num[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            if (i % prime[j] == 0) {
                is_prime[i * prime[j]] = is_prime[i] * prime[j];
                num[i * prime[j]] = num[i] * (is_prime[i] * prime[j] * prime[j] - 1) / (is_prime[i] * prime[j] - 1); // 等比公式推导
                break;
            } else {
                is_prime[i * prime[j]] = prime[j];
                num[i * prime[j]] = num[prime[j]] * num[i];
            }
        }
    }
    for (int i = 0; i <= MAX_N; i++) num[i] -= i;
    return ;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = n; i <= MAX_N; i++) {
        if (num[i] <= MAX_N && num[i] != i && num[num[i]] == i) {
            printf("%d %d\n", i, num[i]);
            break;
        }
    }
    return 0;
}
