/*************************************************************************
	> File Name: p2347.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 15时59分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int num[10] = {0}, fm[6] = {1, 2, 3, 5, 10, 20}, dp[1005] = {0}, ans = 0, sum = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &num[i]);
        sum += (num[i] * fm[i]);
    }
    dp[0] = dp[sum] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < num[i]; j++) {
            for (int l = sum; l >= fm[i]; l--) {
                if (dp[l - fm[i]]) dp[l] = 1;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (dp[i]) ans++;
    }
    printf("Total=%d\n", ans);
    return 0;
}
