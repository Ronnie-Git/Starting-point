/*************************************************************************
	> File Name: 3_P1077_摆花.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 23时02分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

using namespace std;

const int MOD = 1000007;
int dp[105][105] = {0}; // 指摆第i个花后总共摆j盆的最优解

void init(int n) {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    return ;
}

int main() {
    int n, m, t;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= n; i++) {
        cin >> t;
        for (int j = 0; j <= t; j++) {
            for (int k = 0; k <= m - j; k++) {
                if (j == 0 && k == 0) continue;
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][k]) % MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
