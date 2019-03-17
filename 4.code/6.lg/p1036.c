/*************************************************************************
	> File Name: p1036.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月17日 星期六 11时00分39秒
 ************************************************************************/

#include <stdio.h>

int prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int num[30] = {0}, n, k, ans = 0;

void dfs(int ind, int sum, int cnt) {
    if (cnt == k) {
        if (prime(sum)) ans++;
        return ;
    }
    for (int i = ind; i < n; i++) {
        dfs(i + 1, sum + num[i], cnt + 1);
    }
    return ;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}
