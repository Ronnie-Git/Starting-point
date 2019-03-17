#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll check(int *a) {
    if (a[0] == 0) return 0;
    int p[7] = {2, 3, 5, 7, 11, 13, 17}, j = 0;
    ll num = a[0], ret = a[0];
    for (int i = 1 ; i < 10 ; ++i) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if (i < 3) continue;
        num -= 1000 * a[i - 3];
        if (num % p[j++] != 0) return 0;
    }
    return ret;
}
int main() {
    int a[10];
    for (int i = 0 ; i < 10 ; ++i) {
        a[i] = i;
    }
    ll sum = 0;
    do {
        sum += check(a);
    } while (next_permutation(a, a + 10));
    printf("%lld\n", sum);
    return 0;
}
