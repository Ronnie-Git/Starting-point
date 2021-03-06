/*************************************************************************
	> File Name: 47.HZOJ.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月16日 星期三 10时53分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int V, n;
    int v[10005] = {0}, w[10005] = {0}, s[10005] = {0}, dp[10005] = {0};
    cin >> V >> n;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = V; j >= v[i]; j--) {
            int cnt = s[i];
            for (int l = 1; l <= cnt; l++) {
                if (j < l * v[i]) break;
                dp[j] = max(dp[j], dp[j - l * v[i]] + l * w[i]);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
