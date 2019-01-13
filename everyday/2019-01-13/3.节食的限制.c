/*************************************************************************
	> File Name: 3.节食的限制.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 22时41分23秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main() {
    int h, n, num[505] = {0};
    int dp[45005] = {0};
    scanf("%d %d", &h, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = h; j >= num[i]; j--) {
            dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
        }
    }
    printf("%d\n", dp[h]);
    return 0;
}
