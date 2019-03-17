/*************************************************************************
	> File Name: 18_1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 14时57分04秒
 ************************************************************************/

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_N 15

int keep[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &keep[i][j]);
        }
    }
    for (int i = 1; i < MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            int max_num = 0;
            if (j < i) max_num = keep[i - 1][j]; 
            if (j > 0) max_num = max(keep[i - 1][j - 1], max_num);
            keep[i][j] += max_num;
        }
    }
    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        ans = max(keep[MAX_N - 1][i], ans);
    }
    printf("%d\n", ans);
    return 0;
}
