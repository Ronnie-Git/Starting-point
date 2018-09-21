/*************************************************************************
	> File Name: p1909.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月21日 星期五 17时45分02秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, x = 3, ans, w;
    scanf("%d", &n);
    while (x--) {
        int a, b, t;
        scanf("%d %d", &a, &b);
        t = n / a;
        if (n % a) t++;
        w = t * b;
        if (x == 2) ans = w;
        if (w < ans) ans = w;
    }
    printf("%d\n", ans);
    return 0;
}
