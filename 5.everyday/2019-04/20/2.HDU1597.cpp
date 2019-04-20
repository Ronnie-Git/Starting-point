/*************************************************************************
	> File Name: 1.HDU1597.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月20日 星期六 08时36分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {
    LL t, n;
    while (cin >> t) {
        while (t--) {
            cin >> n;
            LL x = ceil((sqrt(8 * n) - 1) / 2);
            LL sum = x * (x - 1) / 2;
            cout << (n - sum - 1) % 9 + 1 << endl;
        }
    }
    return 0;
}
