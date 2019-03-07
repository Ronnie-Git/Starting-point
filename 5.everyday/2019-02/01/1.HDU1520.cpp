/*************************************************************************
	> File Name: 1.HDU1520.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月01日 星期五 09时55分37秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

#define N 6010

int num[N] = {0}, dp[N][2] = {0}, f[N] = {0},n;
vector<int> E[N]; // 存节点的子节点

void dfs(int cur) {
    dp[cur][1] = num[cur];
    for (int i = 0; i < E[cur].size(); i++) {
        int son = E[cur][i];
        dfs(son);
        dp[cur][0] += max(dp[son][1], dp[son][0]);
        dp[cur][1] += dp[son][0];
    }
    return ;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            E[i].clear();
            dp[i][0] = dp[i][1] = 0;
            f[i] = -1;
        }
        int a, b;
        while (scanf("%d%d", &a, &b) != EOF) {
            if (a == 0 && b == 0) break;
            E[b].push_back(a);
            f[a]=b;
        }
        int root = 1;
        while (f[root] != -1) root = f[root]; // 找根节点
        dfs(root);
        cout << max(dp[root][1], dp[root][0]) << endl;
    }
    return 0;
}
