/*************************************************************************
	> File Name: p1014.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月01日 星期六 14时00分02秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, i = 0, s = 0;
    cin >> n;
    while (++i) {
        if (s + i >= n) break;
        s += i;
    }
    if (i % 2) cout << i + 1 + s - n << "/" << n - s;
    else cout << n - s << "/" << i + 1 + s - n;
    return 0;
}
