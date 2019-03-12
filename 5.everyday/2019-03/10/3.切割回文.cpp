/*************************************************************************
	> File Name: 3.切割回文.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月12日 星期二 17时00分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 500005;

int dp[MAX_N] = {0};
char str[MAX_N] = {0};
vector<int> num[MAX_N];

void huiwen(int i, int j) {
    while (i >= 0 && str[j] && str[i] == str[j]) {
        num[j].push_back(i);
        --i, ++j;
    }
    return ;
}

int main() {
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        huiwen(i, i);
        huiwen(i, i + 1);
    }
    for (int i = 1; i < n; i++) {
        dp[i] = i;
        for (int j = 0; j < num[i].size(); j++) {
            if (num[i][j] == 0) {
                dp[i] = 0;
                break;
            }
            dp[i] = min(dp[i], dp[num[i][j] - 1] + 1);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
