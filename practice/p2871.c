/*************************************************************************
	> File Name: p2871.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 12时40分51秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m, c, w;
    int ans[13000] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &w);
        for (int j = m; j >= c; j--) {
            ans[j] = max(ans[j], ans[j - c] + w);
        }
    }
    printf("%d\n", ans[m]);
    return 0;
}
