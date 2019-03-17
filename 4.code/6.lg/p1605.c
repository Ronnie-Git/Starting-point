/*************************************************************************
	> File Name: p1605.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月28日 星期五 19时27分04秒
 ************************************************************************/

#include <stdio.h>

int vis[6][6] = {0};
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

int n, m, ans = 0;
int startx, starty, endx, endy;

void seach(int x, int y) {
    if (x == endx && y == endy) {
        ans++;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        int now_x = x + dir[i][0], now_y = y + dir[i][1];
        if (now_x > m || now_x < 1 || now_y > n || now_y < 1) continue;
        if (vis[now_y][now_x]) continue;
        vis[now_y][now_x] = 1;
        seach(now_x, now_y);
        vis[now_y][now_x] = 0;
    }
    return ;
}

int main() {
    int t;
    scanf("%d %d %d", &n, &m, &t);
    scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
    vis[starty][startx] = 1;
    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        vis[y][x] = 1;
    }
    seach(startx, starty);
    printf("%d\n", ans);
    return 0;
}
