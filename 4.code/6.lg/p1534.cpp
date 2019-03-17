/*************************************************************************
	> File Name: p1534.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月30日 星期四 08时37分33秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, a[5], t = 0, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[0] >> a[1];
        t = t + a[0] + a[1] - 8;
        s += t;
    }
    cout << s;
    return 0;
}
