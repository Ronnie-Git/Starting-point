/*************************************************************************
	> File Name: 1.49.HZOJ.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月18日 星期五 09时59分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1000000

struct num {
    int v, w;
} num[MAX_N + 5];

int main() {
    int V, n, v, w, s, cnt = 0;
    int dp[10005] = {0};
    cin >> V >> n;
    for (int i = 0; i < n; i++) {
        cin >> v >> w >> s;
        for (int j = 1; j <= s; j <<= 1) {
            num[cnt].v = j * v;
            num[cnt++].w = j * w;
            s -= j;
        }
        if (s > 0) {
            num[cnt].v = s * v;
            num[cnt++].w = s * w;
        }
    } 
    for (int i = 0; i < cnt; i++) {
        for (int j = V; j >= num[i].v; j--) {
            dp[j] = max(dp[j], dp[j - num[i].v] + num[i].w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
