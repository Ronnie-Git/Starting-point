/*************************************************************************
	> File Name: p2639.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 18时46分46秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n, num[505] = {0}, dp[45005] = {0};
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= num[i]; j--) {
            dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
        }
    }

    printf("%d\n", dp[m]);
    return 0;
}
