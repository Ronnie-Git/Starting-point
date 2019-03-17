/*************************************************************************
	> File Name: 6.F.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 10时18分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

LL func(LL a, LL b, LL c) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % c;
        }
        a = (a % c) * (a % c) % c;
        b >>= 1;
    }
    return ans % c;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        cout << func(a, b, c) << endl;
    }
    return 0;
}
