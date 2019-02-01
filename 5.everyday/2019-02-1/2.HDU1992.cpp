/*************************************************************************
	> File Name: 2.HDU1992.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月01日 星期五 20时14分01秒
 ************************************************************************/

#include <iostream>

using namespace std;
 
int dp[1005][16] = {0};
 
void dfs(int r, int c, int cur, int next) {
//分别表示当前行，当前列,当前状态，可转移的状态
    if (c > 3) {
        dp[r + 1][next] += dp[r][cur];
        return;
    }
    if (!(cur & (1 << c))) {
        dfs(r, c + 1, cur, next | (1 << c));   //竖着放，用1
        if (c <= 2 && !(cur & (1 << (c + 1)))) {
            dfs(r, c + 2, cur, next);  //也可以横着放，两个0
        }
    } else {
        dfs(r, c + 1, cur, next);   //位置被上面的占了
    }
    return ;
}

void init() {
    dp[0][0] = 1;
    for (int i = 0; i < 22; i++) {   //22已经爆int32了
        for(int j = 0; j < 16; j++) {
            if (dp[i][j]) dfs(i, 0, j, 0);
        }
    }
    return ;
}
 
int main() {
    init();
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << i << " " << dp[x][0] << endl;
    }
    return 0;
}
