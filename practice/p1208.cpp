/*************************************************************************
	> File Name: p1208.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月03日 星期三 16时25分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct milk {
    int x, num;
} n[10000];

bool cmp(milk a, milk b) {
    return a.x < b.x;
}

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &n[i].x, &n[i].num);
    }
    sort(n, n + M, cmp);
    for (int i = 0; i < M; i++) {
        if (n[i].num < N) {
            N -= n[i].num;
            ans += n[i].num * n[i].x;
        } else {
            ans += N * n[i].x;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
