/*************************************************************************
	> File Name: 1.P1101.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月16日 星期四 19时37分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int dir[8][2] = {
    0, 1, 0, -1, 1, 0, -1, 0, 
    1, 1, -1, -1, 1, -1, -1, 1
};
char pattern[] = "yizhong";
char arr[105][105] = {0}, ans[105][105] = {0};
int n;

int dfs(int x, int y, int ind, int k) {
    if (ind == 7) return 1;
    if (x < 0 || y < 0 || x >= n || y >= n || arr[x][y] != pattern[ind]) return 0;

    if (dfs(x + dir[k][0], y + dir[k][1], ind + 1, k)) {
        ans[x][y] = pattern[ind];
        return 1;
    }
    return 0;
}

void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (ans[i][j] ? ans[i][j] : '*');
        }
        cout << endl;
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 8; k++) {
                if (arr[i][j] != 'y') continue;
                dfs(i, j, 0, k);
            }
        }
    }
    output();
    return 0;
}
