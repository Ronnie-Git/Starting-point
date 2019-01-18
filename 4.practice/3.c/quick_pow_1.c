/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月19日 星期三 18时46分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 1000100
#define LL long long int

char d[MAX_N];
int b[MAX_N] = {0};

LL quick_pow(LL x, LL y, int length) {
    LL ans = 1, n = length + b[0];
    while (n) {
        if (b[0] & 1) {
            ans = ans * x % y;
        }
        x = x * x % y;
        
        for (int i = length, flag = 1; i > 0; i--) {
            b[i - 1] += (b[i] & 1) * 10;
            b[i] >>= 1;
            if (flag && !b[i]) length--;
            else flag = 0;
        }
        b[0] >>= 1;
        n = length + b[0];
    }
    return ans % y;
}

int main() {
    LL a, c;
    while (scanf("%lld%s%lld", &a, d, &c) != EOF) {
        int length = strlen(d) - 1;
        for (int i = length, j = 0; i >= 0; i--) {
            b[i] = d[j++] - '0';
        }
        printf("%lld\n", quick_pow(a, c, length));
    }
    return 0;
}

