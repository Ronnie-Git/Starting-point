/*************************************************************************
	> File Name: p2722.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 13时54分31秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    int d[10005] = {0}, w[10005] = {0}, ans[10005] = {0};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &d[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int l = 1; l <= m / d[i]; l++) {
            int temp = l * d[i];
            for (int j = m; j >= temp; j--) {
                ans[j] = max(ans[j], ans[j - temp] + l * w[i]);
            }
        }
    }
    printf("%d\n", ans[m]);
    return 0;
}
