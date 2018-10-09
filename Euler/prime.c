/*************************************************************************
	> File Name: prime.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 20时06分06秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000

int prime[MAX_N + 5] = {0};

void init() {
    prime[0] = 1, prime[1] = 1;
    for (int i = 2; i * i < MAX_N; i++) {
        if(prime[i]) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 0; i < MAX_N; i++) {
        if (prime[i]) continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
