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
    int num[15] = {0}, n, dp[105] = {0};
    for (int i = 0; i < 10; i++) cin >> num[i];
    cin >> n;
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + num[0];
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i - 1] + num[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
