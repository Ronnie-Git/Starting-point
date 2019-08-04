/*************************************************************************
	> File Name: 1.P1443_马的遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 20时44分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Node {
    int x, y;
} node, temp;

int dir[8][2] = {
    {1, 2}, {2, 1}, {-1, 2}, {-2, 1},
    {-1, -2}, {-2, -1}, {1, -2}, {2, -1}
};
int arr[505][505] = {0};
int n, m, sx, sy;

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = -1;
        }
    }
    arr[sx][sy] = 0;
    return ;
}

void bfs() {
    queue<Node> q;
    node.x = sx;
    node.y = sy;
    q.push(node);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = temp.x + dir[i][0], ny = temp.y + dir[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue; //判断越界
            if (arr[nx][ny] == -1) { // 判断是否走过
                node.x = nx;
                node.y = ny;
                q.push(node);
                arr[nx][ny] = arr[temp.x][temp.y] + 1; // 步数加 1
            }
        }
    }
    return ;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    init();
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", arr[i][j]);
		}
        printf("\n");
    }
    return 0;
}
