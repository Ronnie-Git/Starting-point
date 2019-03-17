/*************************************************************************
	> File Name: hwzs_2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月11日 星期二 12时17分54秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int ws(int x) {
    int n = floor(log10(x)) + 1;
    return (n & 1) ? 1 : 0;
}

int hw(int x) {
    int n = x, y = 0;
    while (n) {
        y = 10 * y + n % 10;
        n /= 10;
    }
    return x == y;
}

int prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main () {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b && i <= 10000000; i++) {
        if (i == 11) printf("11\n");
        if (!ws(i)) continue;
        if (!hw(i)) continue;
        if (prime(i)) printf("%d\n", i);
    }
    return 0;
}
