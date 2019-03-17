/*************************************************************************
	> File Name: p1910.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 14时50分12秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int N, M, X;
    int ans[1005][1005] = {0}, a[105] = {0}, b[105] = {0}, c[105] = {0}; 
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= b[i]; j--) {
            for (int l = X; l >= c[i]; l--) {
                ans[j][l] = max(ans[j][l], ans[j - b[i]][l - c[i]] + a[i]);
            }
        }
    }
    printf("%d\n", ans[M][X]);
    return 0;
}
