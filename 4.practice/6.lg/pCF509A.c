/*************************************************************************
	> File Name: pCF509A.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 12时28分00秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, num[12][12] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        num[i][1] = 1;
        num[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            num[i][j] = num[i - 1][j] + num[i][j - 1];
        }
    }
    printf("%d\n", num[n][n]);
    return 0;
}
