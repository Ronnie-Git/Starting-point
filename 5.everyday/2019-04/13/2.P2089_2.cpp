/*************************************************************************
	> File Name: 1.P2089.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月13日 星期六 07时53分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int ans = 0, result[15] = {0};
int num[15] = {1, 10, 55, 210, 615, 1452, 2850, 4740, 6765, 8350, 8953};

void output() {
    for (int i = 0; i < 9; i++) {
        cout << result[i] << " ";
    }
    cout << result[9] << endl;
    return ;
}

void dfs(int ind, int n) {
    if (n < 10 - ind) return ;
    if (ind == 10) {
        if (n == 0) output();
        return ;
    }
    for (int i = 1; i < 4; i++) {
        result[ind] = i;
        dfs(ind + 1, n - i);
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
    cout << (n <= 20 ? num[n - 10] : num[30 - n]) << endl;
    dfs(0, n);
    return 0;
}
