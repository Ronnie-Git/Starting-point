/*************************************************************************
	> File Name: 1.不超过N元钱_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月17日 星期四 16时40分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

typedef struct data {
    int cnt;
    int c[4];
    int w[4];
} data;

int main() {
    data num[70];
    for (int i = 0; i < 70; i++) num[i].cnt = 0;
    int dp[32005] = {0};
    int n, m, a, b, c, ind = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c == 0) {
            num[i].cnt = 1;
            num[i].c[0] = a;
            num[i].w[0] = a * b;
            continue;
        }
        int temp = num[c-1].cnt;
        num[c-1].c[temp] = num[c-1].c[0] + a;
        num[c-1].w[temp] = num[c-1].w[0] + a * b;
        num[c-1].cnt++;
        temp++;
        if (temp == 3) {
            num[c-1].c[temp] = num[c-1].c[1] + a;
            num[c-1].w[temp] = num[c-1].w[1] + a * b;
            num[c-1].cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (num[i].cnt == 0) continue;
        for (int l = n; l >= 0; l--) {
            for (int j = 0; j <= num[i].cnt - 1; j++) {
                if (l - num[i].c[j] < 0) continue;
                dp[l] = max(dp[l], dp[l - num[i].c[j]] + num[i].w[j]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
