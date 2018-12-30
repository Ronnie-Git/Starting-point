/*************************************************************************
	> File Name: p3717.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月08日 星期六 18时41分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int num[105][105] = {0};
int n, m, x, y, r, ans = 0;

double function(int xi, int yj) {
    return sqrt((x - xi) * (x - xi) + (y - yj) * (y - yj));
}

int main() {
    cin >> n >> m >> r;
    while (m--) {
        cin >> x >> y;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                double d = function(i, j);
                if (d <= r) ans += (++num[i][j] == 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
