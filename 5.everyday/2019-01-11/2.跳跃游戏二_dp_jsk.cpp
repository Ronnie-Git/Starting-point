/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月11日 星期五 14时00分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int dp[105] = {0}, num[105] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j <= i + num[i]; j++) {
            if (dp[j] == 0) dp[j] = dp[i] + 1;
            else dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
