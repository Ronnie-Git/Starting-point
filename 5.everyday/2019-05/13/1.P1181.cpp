/*************************************************************************
	> File Name: 1.P1181.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月13日 星期一 16时28分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m, x, sum = 0, ans = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (sum + x > m) {
            sum = x;
            ans += 1;
            continue;
        }
        sum += x;
    }
    cout << ans << endl;
    return 0;
}
