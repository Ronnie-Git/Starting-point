/*************************************************************************
	> File Name: p1003.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 17时32分44秒
 ************************************************************************/

#include <stdio.h>

struct map {
    int a, b, c, d;
} n[10005];

int main() {
    int m, x, y;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &n[i].a, &n[i].b, &n[i].c, &n[i].d);
    }
    scanf("%d %d", &x, &y);
    for (int i = m; i; i--) {
        if (x >= n[i].a && x <= n[i].a + n[i].c && y >= n[i].b && y <= n[i].b + n[i].d) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
