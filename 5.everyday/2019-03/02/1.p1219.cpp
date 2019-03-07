/*************************************************************************
	> File Name: 1.p1219.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月02日 星期六 15时21分55秒
 ************************************************************************/

#include <iostream>

using namespace std;

const int MAX_N = 15;

int ans = 0, n;
int vis_column[MAX_N] = {0}; // 标记列
int vis_MDL[MAX_N << 1] = {0}; // 标记主对角线平行线
int vis_ADL[MAX_N << 1] = {0}; // 标记副对角线平行线
int str[MAX_N] = {0}; // 存满足条件的解

// 输出解
void output() {
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << str[i] + 1;
    }
    cout << endl;
    return ;
}

void dfs(int cnt) {
    if (cnt == n) { // 遍历到n行结束
        ans++;
        if (ans < 4) output();
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (vis_column[i] || vis_MDL[cnt + i] || vis_ADL[n - 1 - cnt + i]) continue; // 判断列、主副对角线平行线是否满足
        str[cnt] = i;
        vis_column[i] = vis_MDL[cnt + i] = vis_ADL[n - 1 - cnt + i] = 1; // 标记
        dfs(cnt + 1);
        vis_column[i] = vis_MDL[cnt + i] = vis_ADL[n - 1 - cnt + i] = 0; // 取消标记
    }
    return ;
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}
