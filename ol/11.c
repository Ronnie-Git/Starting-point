/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 22时24分18秒
 ************************************************************************/

#include<stdio.h>

int dir[4][2] = {0, 1, 1, 1, 1, 0, 1, -1}; // 方向数组

int main() {
    int num[30][30] = {0};
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", num[i] + j);
        }
    }
    int ans = 0;
    for (int i = 5; i < 25; ++i) {
        for (int j = 5; j < 25; ++j) {
            for (int k = 0; k < 4; ++k) { // 四个方向
                int p = 1;
                for (int step = 0; step < 4; ++step) { // 每个方向上四个数
                    int xx = i + step * dir[k][0];
                    int yy = j + step * dir[k][1];
                    p *= num[xx][yy];
                }
                if (p > ans) ans = p; 
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
