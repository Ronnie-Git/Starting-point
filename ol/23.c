/*************************************************************************
	> File Name: 23.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时23分55秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 28150

int prime[MAX_N + 5] = {0};
int ynum[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

int main() {
    int ans = 0;
    for (int i = 2; i * 2 <= MAX_N; i++) { // 计算除本身外因数和
        for (int j = i * 2; j <= MAX_N; j += i) prime[j] += i;
    }
    for (int i = 1; i <= MAX_N; i++) { // 筛盈数
        if (prime[i] > i) ynum[++ynum[0]] = i;
    }
    for (int i = 1; ynum[i] * 2 <= MAX_N; i++) { // 标记两个盈数和
        for (int j = i; ynum[i] + ynum[j] <= MAX_N; j++) {
            is_prime[ynum[i] + ynum[j]] = 1;
        }
    }
    for (int i = 1; i <= MAX_N; i++) {
        if (!is_prime[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
