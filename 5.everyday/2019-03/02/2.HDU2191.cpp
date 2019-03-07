/*************************************************************************
	> File Name: 2.2191.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月02日 星期六 17时41分15秒
 ************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 105;
int dp[MAX_N] = {0};
int n, m;

void pack01(int V, int w, int v) {
    for (int j = V; j >= v; j--) {
        dp[j] = max(dp[j], dp[j - v] + w);
    }
    return ;
}

void fullpack(int V, int w, int v) {
    for (int j = v; j <= V; j++) {
        dp[j] = max(dp[j], dp[j - v] + w);
    }
    return ;
}

void mulpack(int V, int w, int v, int cnt) {
    if (cnt * v >= V) fullpack(V, w, v);
    else {
        // 二进制优化
        int k = 1;
        while (k <= cnt) {
            pack01(V, k * w, k * v);
            cnt -= k;
            k <<= 1;
        }
        if (cnt) pack01(V, cnt * w, cnt * v);
    }
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            int v, w, cnt;
            cin >> v >> w >> cnt;
            mulpack(n, w, v, cnt);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
