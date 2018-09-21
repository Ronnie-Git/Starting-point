/*************************************************************************
	> File Name: p2669.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月21日 星期五 17时46分00秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, ans = 0, j = 0, t = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (j == 0) {
            t++;
            j = t;
        }
        ans += t;
        j--;
    }
    printf("%d\n", ans);
    return 0;
}
