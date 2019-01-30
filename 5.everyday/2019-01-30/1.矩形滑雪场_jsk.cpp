/*************************************************************************
	> File Name: 1.矩形滑雪场_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月30日 星期三 21时18分13秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 110

using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int r, c;
int num[MAX_N][MAX_N] = {0};
int f[MAX_N][MAX_N] = {0};

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y]; // 已经计算过
    int max_temp = 1;
    for (int i = 0; i < 4; i++) {
        int now_x = x + dir[i][0], now_y = y + dir[i][1];
        if (now_x > 0 && now_y > 0 && now_x <= r && now_y <= c && num[now_x][now_y] > num[x][y]) {
            max_temp = max(dfs(now_x, now_y) + 1, max_temp);
        }
    }
    return (f[x][y] = max_temp); // 记忆化
}

int main() {
    int ans = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c;j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1;j <= c; j++) {
            f[i][j] = dfs(i,j);
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
