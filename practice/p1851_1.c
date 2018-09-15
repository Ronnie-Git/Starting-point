/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月15日 星期六 09时48分35秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) prime[i] = 1;
    for (int i = 2; i * i < MAX_N; i++) {
        for (int j = i + i; j <= MAX_N; j += i) {
            prime[j] += i;
        }
    }
    return ;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    do {
        if (n > MAX_N || prime[n] > MAX_N || prime[prime[n]] > MAX_N) continue;
        if (n == prime[prime[n]] && n != prime[n]) {
            printf("%d %d\n", n, prime[n]);
            break;
        }
    } while (++n);
    return 0;
}
