/*************************************************************************
	> File Name: p1068.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月24日 星期一 14时02分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct pm {
    int num;
    int s;
}man[5005];

int cmp(pm a, pm b) {
    if (a.s == b.s) {
        return a.num < b.num;
    }
    return a.s > b.s;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &man[i].num, &man[i].s);
    }

    sort(man, man + n, cmp);

    int k = floor(m * 1.5), x, y = 0;
    for (int i = 0; i < n; i++) {
        if (i == k - 1) {
            x = man[i].s;
        }
        if (i > k - 1 && man[i].s < x) {
            break;
        }
        y++;
    }
    printf("%d %d\n", x, y);

    for (int i = 0; i < y; i++) {
        printf("%d %d\n", man[i].num, man[i].s);
    }

    return 0;
}
