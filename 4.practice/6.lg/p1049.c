/*************************************************************************
	> File Name: p1049.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 15时45分04秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int V, n, v[40] = {0};
    int dp[20005] = {0};
    scanf("%d", &V);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]); 
        }
    }
    
    printf("%d\n", V - dp[V]);
    return 0;
}
