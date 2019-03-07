/*************************************************************************
	> File Name: 1.P1910.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月17日 星期四 14时12分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m, x, a, b, c;
    int dp[1005][1005] = {0};
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for (int j = m; j >= b; j--) {
            for (int l = x; l >= c; l--) {
                dp[j][l] = max(dp[j][l], dp[j - b][l - c] + a);
            }
        }
    }
    cout << dp[m][x] << endl;
    return 0;
}
