/*************************************************************************
	> File Name: 21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时23分55秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 30000

int prime[MAX_N + 5] = {0};

int main() {
    int ans = 0;
    for (int i = 1; i * 2 <= MAX_N; i++) { // 因子求和
        for (int j = i * 2; j <= MAX_N; j += i) prime[j] += i;
    }
    for (int i = 3; i <= 10000; i++) {
        if (i == prime[prime[i]] && i != prime[i]) ans += i; // 亲和数求和
    }
    printf("%d\n", ans);
    return 0;
}
