/*************************************************************************
	> File Name: p1226.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月19日 星期三 16时40分06秒
 ************************************************************************/

#include <stdio.h>

#define LL long long int
LL ans(LL x, LL n, LL y) {
    if (n == 0) return x  % y;
    LL z = 1;
    while (n > 0) {
        if (n & 1) {
            z = z * x % y;
        }
        x = x * x % y;
        n >>= 1;
    }
    return z;
}

int main() {
    LL b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, ans(b, p, k));
    return 0;
}
