/*************************************************************************
	> File Name: 2.P1223.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月13日 星期一 16时35分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
    int ind;
    int ti;
} arr[1005];

bool cmp(Node a, Node b) {
    if (a.ti == b.ti) return a.ind < b.ind;
    return a.ti < b.ti;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].ti;
        arr[i].ind = i + 1;
    }
    sort(arr, arr + n, cmp);
    int temp = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + temp;
        temp += arr[i].ti;
        if (i != 0) cout << " ";
        cout << arr[i].ind;
    }
    printf("\n%.2lf\n", sum / (n * 1.0));
    return 0;
}
