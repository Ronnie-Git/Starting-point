/*************************************************************************
	> File Name: 汽车费用_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 10时49分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int num[150] = {0}, n, dp[105] = {0};
    for (int i = 1; i <= 10; i++) cin >> num[i];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i >= j && j <= 10; j++) {
            if (dp[i] == 0) dp[i] = dp[i - 1] + num[1];
            dp[i] = min(dp[i], dp[i - j] + num[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
