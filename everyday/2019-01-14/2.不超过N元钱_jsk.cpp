/*************************************************************************
	> File Name: 2.不超过N元钱_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 20时13分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct arr {
    int w, data, x;
} arr;

int f[32005][65] = {0};

int main() {
    int n, m, x;
    int dp[32005] = {0};
    arr num[32005] = {0};
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> num[i].w >> num[i].data >> num[i].x;
        num[i].data = num[i].w * num[i].data;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= num[i].w; j--) {
            if (num[i].x) {
                if (f[j][num[i].x]) {
                    dp[j] = max(dp[j], dp[j - num[i].w] + num[i].data);
                } else {
                    int temp_w = num[i].w + num[num[i].x].w;
                    int temp_data = num[i].data + num[num[i].x].data;
                    if (j < temp_w) continue;
                    dp[j] = max(dp[j], dp[j - temp_w] + temp_data);
                    f[j][num[i].x] = 1;
                }
            } else {
                dp[j] = max(dp[j], dp[j - num[i].w] + num[i].data);
                f[j][num[i].x] = 1;
            }
        }
    } 
    cout << dp[n] << endl;
    return 0;
}
