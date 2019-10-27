/*************************************************************************
	> File Name: 5.P2068.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月27日 星期日 20时32分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define maxn 2000010
#define lowbit(a) ((a) & (-a))

int n, m;
int tree[maxn];

void add(int x, int k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
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
    cin >> n >> m;
    int x, y;
    char ch;
    for (int i = 0; i < m; i++) {
        cin >> ch >> x >> y;
        if (ch == 'x') add(x, y);
        else cout << get_sum(y) - get_sum(x - 1) << endl;
    }
    return 0;
}
