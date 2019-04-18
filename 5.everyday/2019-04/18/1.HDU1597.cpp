/*************************************************************************
	> File Name: 1.HDU1597.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月18日 星期四 17时56分29秒
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
const LL MAX_N = 200000;

LL func_exp(LL n) {
    return (n + 1) * n / 2;
}

LL solve(LL n) {
    LL l = 1, r = MAX_N, mid;
    while (l < r) {
        mid = (r + l) / 2;
        if (func_exp(mid) >= n) r = mid;
        else l = mid + 1;
    }
    LL ret = (n - (func_exp(l - 1))) % 9;
    return (ret ? ret : 9);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
