/*************************************************************************
	> File Name: HDU_2191.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月31日 星期四 07时48分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

#define MAX_N 10000

using namespace std;

typedef struct array {
    int c, w;
} array;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int dp[MAX_N + 5] = {0};
        int n, m, cnt = 0;
        array arr[MAX_N + 5];
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int c, w, k;
            cin >> c >> w >> k;
            for (int j = 1; j <= k; j <= 1) {
                arr[cnt].c = j * c;
                arr[cnt++].w = j * w;
                k -= j;
            }
            if (k > 0) {
                arr[cnt].c = k * c;
                arr[cnt++].w = k * w;
            }
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = n; j >= arr[i].c; j--) {
                dp[j] = max(dp[j], dp[j - arr[i].c] + arr[i].w);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
