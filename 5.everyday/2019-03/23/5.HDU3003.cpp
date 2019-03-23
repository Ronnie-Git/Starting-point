/*************************************************************************
	> File Name: 5.HDU3003.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 17时47分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

LL quick_pow(int n) {
    LL ans = 1, base = 2, b = n - 1; 
    while (b) {
        if (b & 1) ans = ans * base % n;
        base = base * base % n;
        b >>= 1;
    }
    return (ans + 1) % n;
}

int main() {
    int x;
    while (cin >> x) {
        if (x == 0) break;
        cout << quick_pow(x) << endl;
    }
    return 0;
}
