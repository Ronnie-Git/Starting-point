/*************************************************************************
	> File Name: 7.P1057.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 19时26分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    int dp[35][35] = {0};
    dp[1][0] = 1;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        dp[1][i] = dp[n][i - 1] + dp[2][i - 1];
        for (int j = 2; j <= n - 1; j++) {
            dp[j][i] = dp[j + 1][i - 1] + dp[j - 1][i - 1];
        }
        dp[n][i] = dp[1][i - 1] + dp[n - 1][i - 1];
    }
    cout << dp[1][m] << endl;
    return 0;
}
