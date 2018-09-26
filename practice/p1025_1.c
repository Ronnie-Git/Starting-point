/*************************************************************************
	> File Name: p1025.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月26日 星期三 17时40分29秒
 ************************************************************************/

#include <stdio.h>

int n, k, ans = 0;

void dfs(int num, int sum, int t) {
    if (t == k) {
        sum == n && ans++;
        return ;
    }
    for (int i = num; (sum + i * (k - t)) <= n; i++) {
        dfs(i, sum + i, t + 1);   
    }
    return ;
}

int main() {
    scanf("%d %d", &n, &k);
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
