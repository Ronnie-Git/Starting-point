/*************************************************************************
	> File Name: p2666.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月23日 星期四 10时51分06秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int n, ans = 0;

void dfs(int num, int sum) {
    if (num == 4) {
        if (sum == n) ans++;
    } else {
        for (int i = 0; i <= sqrt(n); i++) dfs(num + 1, sum + i * i);   
    }
}

int main() {
    scanf("%d", &n);
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
