/*************************************************************************
	> File Name: 2.P1029.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月18日 星期六 09时36分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b, sum = 0;
    cin >> a >> b;
    int c = a * b;
    for (int i = 1; i <= b / a; i++) {
        int x = i * a, y = c / (i * a);
        if (c % x || y % a) continue;
        if (a != gcd(x, y)) continue;
        //cout << i * a << " " << c / (i * a) << endl;
        sum += 1;
    }
    cout << sum << endl;
    return 0;
}
