/*************************************************************************
	> File Name: h.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月21日 星期五 19时34分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int time;
    int num;
}n[1010];

int cmp(node a, node b) {
    return a.time < b.time;
}

int main() {
    int x;
    double ans = 0;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        scanf("%d", &n[i].time);
        n[i].num = i;
    }
    sort(n + 1, n + x + 1, cmp);
    for (int i = 1; i <= x; i++) {
        ans += n[i].time * (x - i);
        printf("%d ", n[i].num);
    }
    printf("\n%.2lf\n", ans / x);
    return 0;
}
