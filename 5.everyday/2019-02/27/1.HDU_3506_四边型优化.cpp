/*************************************************************************
	> File Name: 1.HDU_3506_四边型优化.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月27日 星期三 08时15分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 2010;
const int INF = 0x3f3f3f3f;

int dp[MAX_N][MAX_N] = {0};
int sum[MAX_N] = {0};
int w[MAX_N] = {0};
int num[MAX_N][MAX_N] = {0};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        sum[0] = 0;
        memset(dp, INF, sizeof(dp));
        for (int i = 1; i <= n * 2; i++) {
            if (i <= n) cin >> w[i];
            else w[i] = w[i - n];
            sum[i] = sum[i - 1] + w[i];
            dp[i][i] = 0;
            num[i][i] = i;
        }
        for (int len = 2; len <= n; len++) {
            for (int j = 1; j + len <= n * 2; j++) {
                int ends = j + len - 1;
                for (int i = num[j][ends - 1]; i <= num[j + 1][ends]; i++) {
                    int temp = dp[j][i] + dp[i + 1][ends] + sum[ends] - sum[j - 1];
                    if (dp[j][ends] > temp) {
                        dp[j][ends] = temp;
                        num[j][ends] = i;
                    }
                }
            }
        }
    
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[i][i + n - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
