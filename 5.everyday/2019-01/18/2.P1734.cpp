/*************************************************************************
	> File Name: 2.P1734.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月18日 星期五 14时03分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1000

int sum[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i < MAX_N + 5; i++) {
        for (int j = i; j < MAX_N + 5; j++) {
            if (j % i == 0) sum[j] += i;
        }
    }
    for (int i = 2; i < MAX_N + 5; i++) sum[i] = sum[i] + 1 - i;
    return ;
}

int main() {
    init();
    int n;
    int dp[MAX_N +5] = {0};
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] = max(dp[j], dp[j - i] + sum[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
