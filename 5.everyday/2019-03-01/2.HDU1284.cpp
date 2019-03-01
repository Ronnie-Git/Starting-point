/*************************************************************************
	> File Name: 2.HDU1284.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月01日 星期五 17时07分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 40000;

int dp[MAX_N] = {0};

void init() {
    int num[5] = {1, 2, 3};
    dp[0] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = num[i]; j < MAX_N; j++) {
            dp[j] += dp[j - num[i]];
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
