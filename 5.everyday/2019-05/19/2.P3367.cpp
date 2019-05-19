/*************************************************************************
	> File Name: 2.P3367.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月19日 星期日 09时47分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 10005
int num[MAX_N] = {0};

void init() {
    for (int i = 0; i < MAX_N; i++) {
        num[i] = i;
    }
    return ;
}

int find(int x) {
    if (num[x] == x) return x;
    return (num[x] = find(num[x]));
}

int main() {
    init();
    int n, m;
    int x, y, z;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> z >> x >> y;
        if (z == 1) num[find(x)] = find(y);
        else cout << (find(x) == find(y) ? "Y" : "N") << endl;
    }
    return 0;
}
