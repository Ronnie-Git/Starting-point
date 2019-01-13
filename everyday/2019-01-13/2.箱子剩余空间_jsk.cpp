/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 10时50分54秒
 ************************************************************************/

// 装箱问题 简单背包
// 在超过箱子容量的情况下 尽可能多的用完容量

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m, num[35] = {0}, dp[20005] = {0};
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> num[i];
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= num[i]; j--) { // 防止超过箱子容量
            dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
        }
    }
    cout << n - dp[n] << endl;
    return 0;
}
