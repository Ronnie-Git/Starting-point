/*************************************************************************
	> File Name: 2.HDU_1114.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月27日 星期三 15时07分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 10010;
int dp[MAX_N] = {0};

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        int n, w, m, e, f, V;
        cin >> e >> f;
        V = f - e;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w >> m;
            for (int j = m; j <= V; j++) {
                dp[j] = min(dp[j], dp[j - m] + w);
            }
        }
        if (dp[V] < INF) {
            cout << "The minimum amount of money in the piggy-bank is " << dp[V] << "." << endl;
        } else {
            cout << "This is impossible." << endl;
        }
    }
    return 0;
}
