/*************************************************************************
	> File Name: quick_pow.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 19时38分06秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int quick_pow(int x, int n) {
    int base = x, ans = 1;
    while (n) {
        if (n & 1) ans *= base;
        base *= base;
        n >>= 1;
    }
    return ans;
}

int main() {
    int x, n;
    while (scanf("%d %d", &x, &n) != EOF) {
        int a = quick_pow(x, n), b = (int)pow(x, n);
        printf("%d = %d %s\n", a, b, (a == b ? "True" : "False"));
    } 
    return 0;
}
