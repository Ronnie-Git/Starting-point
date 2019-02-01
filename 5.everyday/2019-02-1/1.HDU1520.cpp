/*************************************************************************
	> File Name: 1.HDU1520.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月01日 星期五 09时55分37秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
 
using namespace std;
 
#define MAX_N 6005
 
int n;
int dp[MAX_N][2] = {0}, father[MAX_N] = {0};//dp[i][0]0表示不去，dp[i][1]1表示去了
bool vis[MAX_N] = {0};
 
void tree_dp(int node) {
    vis[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && father[i] == node) {//i为下属
            tree_dp(i);//递归调用孩子结点，从叶子结点开始dp
            //关键
            dp[node][1] += dp[i][0];//上司来,下属不来
            dp[node][0] += max(dp[i][1], dp[i][0]);//上司不来，下属来、不来
        }
    }
    return ;
}
 
int main() {
    int f, c, root;
    while (scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        memset(father, 0, sizeof(father));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) cin >> dp[i][1];
        root = 0;//记录父结点
        int flag = 1;
        while (scanf("%d %d", &c, &f) != EOF && (c || f)) {
            father[c] = f;
            if (root == c || flag) root = f;
        }
        // 找父节点
        while (father[root]) root = father[root];
        tree_dp(root);
        cout << max(dp[root][0],dp[root][1]) << endl;
    }
    return 0;
}

