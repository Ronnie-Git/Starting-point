/*************************************************************************
	> File Name: 1.HDU_1159.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年06月11日 星期二 19时24分10秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define SIZE 1005
int dp[SIZE][SIZE] = {0};
char a[SIZE] = {0}, b[SIZE] = {0};

int main() {
    while (cin >> a >> b) {
        int lena = strlen(a), lenb = strlen(b);
        for (int i = 1; i <= lena; i++) {
            for (int j = 1; j <= lenb; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[lena][lenb] << endl;
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    return 0;
}
