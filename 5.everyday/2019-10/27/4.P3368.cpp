/*************************************************************************
	> File Name: 4.P3368.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月27日 星期日 20时09分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#define maxn 2000010
int n, m;
int arr[maxn];
int tree[maxn];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}

int search(int x) {
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    int op, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            add(x, z);
            add(y + 1,-z);
        } else {
            cin >> x;
            cout << arr[x] + search(x) << endl;
        }
    }
    return 0;
}
