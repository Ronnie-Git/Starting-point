/*************************************************************************
	> File Name: 18.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 14时26分05秒
 ************************************************************************/
// 正向递推 用递归
#include <stdio.h>

#define MAX_N 15

int map[MAX_N + 5][MAX_N + 5];
int keep[MAX_N + 5][MAX_N + 5] = {0}; // 记忆化数组

int solve(int i, int j) {
    if (i == MAX_N) return 0;
    if (keep[i][j]) return keep[i][j]; // 之前走过直接返回
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j + 1); // lnum左 rnum右
    keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j]; // 记忆每个位置开始往下走的最大值
    return keep[i][j];
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}
