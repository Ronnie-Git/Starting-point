/*************************************************************************
	> File Name: 1.开心的金明_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 19时55分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct arr {
    int w, data;
} arr;

int main() {
    int n, m, dp[30005] = {0};
    arr num[30005];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> num[i].w >> num[i].data;
        num[i].data *= num[i].w;
    }
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= num[i].w; j--) {
            dp[j] = max(dp[j], dp[j - num[i].w] + num[i].data);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
