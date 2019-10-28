#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define maxn 2000010
#define lowbit(a) ((a) & (-a))
int n, m;
int arr[maxn];
int tree[maxn];

void add(int x) { //这个函数用来在树状数组中直接修改
    while(x <= n) tree[x] ^= 1, x += lowbit(x);
}
void range_add(int l, int r) { //给区间[l, r]加上x
    add(l), add(r + 1);
}
int ask(int x) { //单点查询
    int res = 0;
    while(x) res ^= tree[x], x -= lowbit(x);
    return res;
}

int main() {
    int op, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            range_add(x, y);
        } else {
            cin >> x;
            cout << arr[x] + ask(x) << endl;
        }
    }
    return 0;
}
