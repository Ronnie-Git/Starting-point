/*************************************************************************
	> File Name: 1.P1002.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月24日 星期日 17时50分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int map_arr[25][25] = {0};
int b_x = 0, b_y = 0, m_x = 0, m_y = 0;
int dir[8][2] = {-1, -2, -2, -1, -1, 2, -2, 1, 1, -2, 2, -1, 1, 2, 2, 1};
long long int dp[25][25] = {0};

// 初始化马的位置和马能走到的位置
void init_map_arr() {
    map_arr[m_y][m_x] = 1;
    for (int i = 0; i < 8; i++) {
        int x = m_x + dir[i][0], y = m_y + dir[i][1];
        if (x < 1 || x > 21 || y < 1 || y > 21) continue;
        map_arr[y][x] = 1;
    }
    return ;
}

int main() {
    cin >> b_x >> b_y >> m_x >> m_y;
    ++b_x, ++b_y, ++m_x, ++m_y;
    init_map_arr();
    dp[1][1] = 1;
    for (int i = 1; i <= b_y; i++) {
        for (int j = 1; j <= b_x; j++) {
            if (i == 1 && j == 1) continue;
            if (map_arr[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[b_y][b_x] << endl;
    return 0;
}
