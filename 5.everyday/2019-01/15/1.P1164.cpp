/*************************************************************************
	> File Name: 1.P1164.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月15日 星期二 11时50分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int num[105] = {0}, dp[10005] = {0};
    dp[0] = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= num[i]; j--) {
            dp[j] += dp[j - num[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}
