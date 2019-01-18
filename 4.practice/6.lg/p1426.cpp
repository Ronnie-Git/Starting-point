/*************************************************************************
	> File Name: P1426.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月28日 星期二 12时58分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    double x, y, s = 0, t = 7;
    cin >> x >> y;
    while (s < x - y) {
        s += t;
        t *= 0.98;
    }
    if (t*0.98 <= x + y - s) {
        cout << "y";
    } else {
        cout << "n";
    }
    return 0;
}
