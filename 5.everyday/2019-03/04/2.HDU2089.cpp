/*************************************************************************
	> File Name: 2.HDU2089.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月04日 星期一 19时48分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 20;
int dp[MAX_N][2] = {0};
int num[MAX_N] = {0};
int n = 0, m = 0;

int dfs(int cnt, int flag, int limit) {
    if (cnt == -1) return 1;
    if (!limit && dp[cnt][flag] != -1) return dp[cnt][flag];
    int ind = (limit ? num[cnt] : 9), temp = 0;
    for (int i = 0; i <= ind; i++) {
        if (flag && i == 2) continue;
        if (i == 4) continue;
        temp += dfs(cnt - 1, i == 6, limit && i == num[cnt]);
    }
    if (!limit) dp[cnt][flag] = temp;
    return temp;
}

int solve(int x) {
    int cnt = 0;
    while (x) {
        num[cnt++] = x % 10;
        x /= 10;
    }
    return dfs(cnt - 1, 0, 1);
}

int main() {
    while (cin >> n >> m && n && m) {
        memset(dp, -1, sizeof(dp));
        cout << solve(m) - solve(n - 1) << endl;
    }
    return 0;
}
