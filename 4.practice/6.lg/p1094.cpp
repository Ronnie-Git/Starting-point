/*************************************************************************
	> File Name: p1094.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月29日 星期四 20时35分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0, n, max, num[30005] = {0};
    scanf("%d %d", &max, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int l = 0, r = n - 1;
    while (l <= r) {
        if (num[l] + num[r] <= max) l++;
        r--;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
