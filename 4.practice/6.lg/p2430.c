/*************************************************************************
	> File Name: p2430.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 13时28分29秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int a, b, x, c, n, m, p, q, max_time;
    int num[5005] = {0}, t[5005] = {0}, w[5005] = {0}, ans[5005] = {0};
    scanf("%d %d", &a, &b);
    x = b / a;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        num[i] = c * x;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p, &q);
        t[i] = num[p];
        w[i] = q;
    }
    scanf("%d", &max_time);

    for (int i = 0; i < m; i++) {
        for (int j = max_time; j >= t[i]; j--) {
            ans[j] = max(ans[j], ans[j - t[i]] + w[i]);
        }
    }
    printf("%d\n", ans[max_time]);
    return 0;
}
