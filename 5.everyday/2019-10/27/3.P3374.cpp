/*************************************************************************
	> File Name: 3.P3374.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月27日 星期日 19时46分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define maxn 2000010
int n, m, tree[maxn];
int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
    return ;
}

int get_sum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    int a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) add(b, c);
        else cout << get_sum(c) - get_sum(b - 1) << endl;
    }
    return 0;
}
