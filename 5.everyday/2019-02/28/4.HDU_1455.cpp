/*************************************************************************
	> File Name: 4.HDU_1455.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月27日 星期三 20时39分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
 
int n, num, sum; // n表示木棍的数量，sum表示n个木棍的总长度
 
int len[100] = {0}; // 木棍的长度
int vis[100] = {0}; // 标记这根木棍是否被用过
 
int cmp(int a, int b) {
    return a > b;
}
 
// length为当前木棒的长度，cnt统计当前长度木棒的数量，l拼接的长度
int dfs(int length, int cnt, int l, int ind) {
    if (length == sum) return 1;
    if (cnt == num) return 1;
 
    for (int i = ind; i < n; i++) {
        if (vis[i]) continue;
        if (length == len[i] + l) {
            vis[i] = 1;
            if (dfs(length, cnt + 1, 0, 0)) return 1;
            vis[i] = 0;
            return 0;
        }
        if (length > len[i] + l) {
            vis[i] = 1;
            l += len[i];
            if (dfs(length, cnt, l, i + 1)) return 1;
            l -= len[i];  // 如果不能拼接，那么就恢复
            vis[i] = 0;
            if (l == 0) return 0;
            while (len[i] == len[i + 1]) ++i; // 剪枝
        }
    }
    return 0;
}
 
int main() {
    while (cin >> n && n) {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            cin >> len[i];
            sum += len[i];
        }
        sort(len, len + n, cmp);

        for (int i = len[0]; i <= sum; i++) {
            if (sum % i) continue;
            num = sum / i; 
            if (dfs(i, 0, 0, 0)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
