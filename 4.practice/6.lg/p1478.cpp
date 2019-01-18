/*************************************************************************
	> File Name: p1478.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月06日 星期六 10时59分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, x, y, t = 0, ans = 0, num[5005] = {0};
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = 0; i < a; i++) {
        scanf("%d %d", &x, &y);
        if (x > c + d) continue;
        num[t++] = y;
    }
    sort(num, num + t);
    for (int i = 0; i < t; i++) {
        if (num[i] > b) break;
        ans++;
        b -= num[i];
    }
    printf("%d\n", ans);
    return 0;
}
