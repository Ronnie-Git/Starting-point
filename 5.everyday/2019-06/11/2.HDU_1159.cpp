/*************************************************************************
	> File Name: 2.HDU_1159.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年06月11日 星期二 19时54分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

#define swap(a, b) { a ^= b; b ^= a; a ^= b; }
#define SIZE 1005
int dp[2][SIZE] = {0};
char a[SIZE] = {0}, b[SIZE] = {0};

using namespace std;

int main() {
    while (cin >> a >> b) {
        int lena = strlen(a), lenb = strlen(b);
        int now = 1, pre = 0;
        for (int i = 0; i < lena; i++) {
            swap(now, pre);
            for (int j = 0; j < lenb; j++) {
                if (a[i] == b[j]) {
                    dp[now][j + 1] = dp[pre][j] + 1;
                } else {
                    dp[now][j + 1] = max(dp[pre][j + 1], dp[now][j]);
                }
            }
        }
        cout << dp[now][lenb] << endl;
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    return 0;
}
