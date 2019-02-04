/*************************************************************************
	> File Name: 2.滑雪_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月28日 星期一 22时17分41秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 110

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int r,c;
int m[MAX_N][MAX_N] = {0};
int f[MAX_N][MAX_N] = {0};

int dfs(int x, int y) {
    if (f[x][y]!=0) return f[x][y];
    int maxt = 1;
    int t;
    for (int i=0;i<4;i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx>0&&ty>0&&tx<=r&&ty<=c&&m[tx][ty]>m[x][y]) {
            t = dfs(tx,ty)+1;
            maxt = max(t, maxt);
        }
    }
    f[x][y] = maxt;
    return maxt;
}
int main () {
    scanf("%d%d", &r, &c);
    for (int i=1;i<=r;i++)
    for (int j=1;j<=c;j++)
    scanf("%d", &m[i][j]); 
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i=1;i<=r;i++)
    for (int j=1;j<=c;j++) {
        f[i][j] = dfs(i,j);
        ans = max(ans, f[i][j]);
    }
    printf("%d\n", ans);
    return 0;
}
