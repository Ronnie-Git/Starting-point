/*************************************************************************
	> File Name: p1056.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月09日 星期二 22时39分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct zy {
    int sum;
    int num;
} k[1005], l[1005];

bool cmp1(zy p, zy q) {
    return p.sum > q.sum;
}

bool cmp2(zy p, zy q) {
    return p.num < q.num;
}

void init() {
    for (int i = 0; i < 1005; i++) {
        k[i].sum = 0;
        l[i].sum = 0;
    }
}

int main() {
    init();
    int a, b, c, d, e;
    scanf("%d %d %d %d %d" ,&a, &b, &c, &d, &e);
    for (int i = 0; i < e; i++) {
        int x, y, n, m;
        scanf("%d %d %d %d", &x, &y, &n, &m);
        if (x == n) {
            int t = min(y, m);
            l[t].sum++;
            l[t].num = t;
        }
        if (y == m) {
            int t = min(x, n);
            k[t].sum++;
            k[t].num = t;
        }
    }
    sort (k + 1, k + 1003, cmp1); 
    sort (l + 1, l + 1003, cmp1); 
    sort (k + 1, k + c + 1, cmp2); 
    sort (l + 1, l + d + 1, cmp2);
    for (int i = 1; i <= c; i++) {
        i > 1 && printf(" ");
        printf("%d", k[i].num);
    }
    printf("\n");
    for (int i = 1; i <= d; i++) {
        i > 1 && printf(" ");
        printf("%d", l[i].num);
    }
    printf("\n");
    return 0;
}
