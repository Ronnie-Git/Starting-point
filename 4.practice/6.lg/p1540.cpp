/*************************************************************************
	> File Name: p1540.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月08日 星期一 18时20分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    queue <int> q;
    int num[1005] = {0};
    int n, m, ans = 0, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (num[x]) continue;
        ans++;
        num[x] = 1;
        if (q.size() < n) {
            q.push(x);
        } else {
            int p = q.front();
            num[p] = 0;
            q.pop();
            q.push(x);
        }
    }
    printf("%d\n", ans);
    while (!q.empty()) q.pop();
    return 0;
}
