/*************************************************************************
	> File Name: 10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 01时57分54秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAN_N 2000000

int prime[MAN_N + 5] = {0};

int main() {
    int64_t ans = 0;
    for (int i = 2; i <= MAN_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            ans += i; 
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAN_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }    
    }
    printf("%" PRId64 "\n", ans);
}
