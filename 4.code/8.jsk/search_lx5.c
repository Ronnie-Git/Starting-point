/*************************************************************************
	> File Name: search_lx5.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 17时26分30秒
 ************************************************************************/

#include <stdio.h>

#define N 100000

int main() {
    int num[N + 5] = {0};
    int n, a, j = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        num[a] = 1;
    }
    while (j++ < N) {
        if (num[j]) continue;
        printf("%d\n", j);
        break;
    }
    return 0;
}
