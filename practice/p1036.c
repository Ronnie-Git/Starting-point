/*************************************************************************
	> File Name: p1036.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月23日 星期四 15时06分44秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;
int n, k, num = 0, s = 0, y = 0;
long long int a[30];

int prime(int d) {
    for (int i = 2; i * i <= d; ++i) {
        if (d % i == 0) return 0;
    }
    return 1;
}
void dfs(int x) {
    if (y == k) {
        if (prime(s)) {
            num++;
            return;
        }
    }
    for (int i = x; i < n; ++i) {
        s += a[i];
        y++;
        dfs(i + 1);
        y--;
        s -= a[i];
    }
    return ;
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dfs(0);
    cout << num;
    return 0;
}
