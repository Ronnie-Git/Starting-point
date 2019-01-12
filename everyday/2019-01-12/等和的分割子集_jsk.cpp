/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月12日 星期六 17时47分38秒
 ************************************************************************/

// dp[i][j] : 从1...n的前 i 个数中选择若干个，使得总和为j
// dp[i][j] = dp[i - 1][j - i] + dp[i - 1][j]
// 两项分别对应 选择 i、不选 i

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, key;
    cin >> n;
    key = (n + 1) * n / 2;
    if (key & 1) {
        cout << "0" << endl;
        return 0;
    }
    key /= 2;
    long long int dp[650] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = key; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[key] / 2 << endl;
    return 0;
}
