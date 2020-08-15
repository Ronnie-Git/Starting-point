/*************************************************************************
	> File Name: HZ42_练习题3_钱币问题.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Aug 2020 11:49:33 AM CST
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int mod = 9973;
const int MAXN = 30005;
int arr[MAXN];
int dp[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <= m; ++j) {
            dp[j] = (dp[j - arr[i]] + dp[j]) % mod;
        }
    }

    cout << dp[m] << endl;
    return 0;
}
