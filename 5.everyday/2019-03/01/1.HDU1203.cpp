/*************************************************************************
	> File Name: 1.HDU1203.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月01日 星期五 16时22分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 10010;
double dp[MAX_N] = {0};
int v[MAX_N] = {0};
double w[MAX_N] = {0};

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
        for (int i = 0; i <= n; i++) dp[i] = 1;
        for (int i = 0; i < m; i++) {
            cin >> v[i] >> w[i];
            w[i] = 1 - w[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = n; j >= v[i]; j--) {
                dp[j] = min(dp[j], dp[j - v[i]] * w[i]);
            }
        }
        printf("%.1lf%%\n", (1.0 - dp[n]) * 100.0);
    }
    return 0;
}
