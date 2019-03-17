/*************************************************************************
	> File Name: p1025_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月26日 星期三 18时12分41秒
 ************************************************************************/

#include <stdio.h>

int n, f[205][10] = {0}, k;

void init() { // 边界
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        f[i][1] = 1;
    }
    for (int i = 2; i <= k; i++) {
        f[1][i] = 0;
        f[0][i] = 0;
    }
    return ;
}

int main() {
    scanf("%d %d", &n, &k);
    init();
    // 状态转移方程 有1的：f[i][j] = f[i-1][j-1] + f[i-j][j] 没1的：f[i][j] = f[i-j][j]
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i > j) f[i][j] = f[i - j][j];
            f[i][j] += f[i - 1][j - 1]; 
        }
    }
    printf("%d\n", f[n][k]);
    return 0;
}
