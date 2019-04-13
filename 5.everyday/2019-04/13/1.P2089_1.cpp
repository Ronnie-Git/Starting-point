/*************************************************************************
	> File Name: 1.P2089.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月13日 星期六 07时53分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ans = 0;
char result[60000][15] = {0};

void dfs(int ind, int n) {
    if (n < 10 - ind) return ;
    if (ind == 10) {
        if (n == 0) {
            strcpy(result[ans + 1], result[ans]);
            ans += 1;
        }
        return ;
    }
    for (int i = 1; i < 4; i++) {
        result[ans][ind] = i + '0';
        dfs(ind + 1, n - i);
    }
    return ;
}

void output() {
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        for (int j = 0; j < 9; j++) {
            cout << result[i][j] << " ";
        }
        cout << result[i][9] << endl;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    if (n < 10 || n > 30) {
        cout << "0" << endl;
        return 0;
    }
    dfs(0, n);
    output();
    return 0;
}
