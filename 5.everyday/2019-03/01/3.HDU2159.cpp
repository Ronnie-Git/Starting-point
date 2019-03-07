/*************************************************************************
	> File Name: 3.HDU2159.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月01日 星期五 18时05分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 110;
const int INF = 0x3f3f3f3f;
int dp[MAX_N] = {0}, cnt[MAX_N] = {0};

//以忍耐度为背包，经验为dp值，在dp时记录杀怪的次数
//再扫一边背包，看是否有经验值达到要求的

int main() {
    int n, m, k, s, a, b;
    while (cin >> n >> m >> k >> s) {
        memset(dp, -INF - 1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[0] = 0;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            for (int j = b; j <= m; j++) {
                if (cnt[j - cnt[b]] + 1 > s) break;
                if (dp[j] < dp[j - b] + a) {
                    dp[j] = dp[j - b] + a;
                    cnt[j] = cnt[j - b] + 1;
                }
            }
        }
        int ind = 1;
        while (dp[ind] < n && ind <= m) ++ind;
        printf("%d\n", ind > m ? -1 : m - ind);
    }
    return 0;
}
