/*************************************************************************
	> File Name: p1164.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月03日 星期一 20时38分30秒
 ************************************************************************/

#include<iostream>

using namespace std;
int n, m, v[10005], dp[10005];
int main() {
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[m];
    return 0;
}
