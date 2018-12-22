/*************************************************************************
	> File Name: p1583.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 20时00分40秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct data {
    int num, w;
} data;

bool cmp(data x, data y) {
    if (x.w == y.w) return x.num < y.num;
    return x.w > y.w;
}

int main() {
    data arr[20005];
    int n, E[15] = {0}, x, k;
    cin >> n >> k;
    for (int i = 1; i <= 10; i++) {
        cin >> E[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i].num = i + 1;
        arr[i].w = x;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        arr[i].w += E[(i % 10 + 1)];
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < k; i++) {
        if (i) cout << " ";
        cout << arr[i].num;
    }
    cout << endl;
    return 0;
}
