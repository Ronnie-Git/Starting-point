/*************************************************************************
	> File Name: p1464.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月06日 星期六 11时30分23秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (a <= b || a <= c) {
        return (long long)pow(2, a);
    } else {
        return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}

int main() {
    long long int  a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c)) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c)); 
    }
    return 0;
}
