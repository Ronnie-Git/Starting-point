/*************************************************************************
	> File Name: 42.HZOJ.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月16日 星期三 12时47分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MOD 9973

using namespace std;

int main() {
    int m, n;
    int x, dp[10005] = {0};
    cin >> m >> n;
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        cin >> x;
        for (int j = x; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
