/*************************************************************************
	> File Name: 1.HDU1520.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月04日 星期一 18时35分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 10000;
int num[MAX_N] = {0}, n = 0;
int dp[MAX_N][2] = {0};
int father[MAX_N] = {0};

// 存每个节点的孩子
vector<int> v[MAX_N];

void dfs(int root) {
    dp[root][1] = num[root];
    for (int i = 0; i < v[root].size(); i++) {
        int son = v[root][i];
        dfs(son);
        dp[root][1] += dp[son][0]; // 选当前点
        dp[root][0] += max(dp[son][0], dp[son][1]); // 不选当前点
    }
    return ;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            v[i].clear();
            dp[i][0] = dp[i][1] = 0;
            father[i] = 0;
        }
        int l, k;
        while (cin >> l >> k) {
            if (l == 0 && k == 0) break;
            v[k].push_back(l);
            father[l] = k;
        }
        int root = 1;
        while (father[root]) root = father[root]; // 找根节点
        dfs(root);
        cout << max(dp[root][0], dp[root][1]) << endl;
    }
    return 0;
}
