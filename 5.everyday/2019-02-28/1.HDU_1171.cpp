/*************************************************************************
	> File Name: 1.HDU_1171.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月27日 星期三 14时12分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 50010;
const int MAX_M = 300005;

int v[MAX_N] = {0};
int dp[MAX_M] = {0};

int main() {
    int n;
    while (cin >> n && n > 0) {
        int sum = 0, x, y, cnt = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            sum += x * y;
            while (y--) v[cnt++] = x;
        }
        int sum_half = sum / 2;
        for (int i = 0; i < cnt; i++) {
            for (int j = sum_half; j >= v[i]; j--) {
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
            }
        }
        cout << sum - dp[sum_half] << " " << dp[sum_half] << endl;
    }
    return 0;
}
