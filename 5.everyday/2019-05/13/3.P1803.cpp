/*************************************************************************
	> File Name: 3.P1803.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月13日 星期一 16时49分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1000005

struct Node {
    int sti, eti;
} arr[MAX_SIZE];

bool cmp(Node a, Node b) {
    if (a.eti == b.eti) return a.sti < b.sti;
    return a.eti < b.eti;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].sti >> arr[i].eti;
    }
    sort(arr, arr + n, cmp);
    int ans = 0, temp_eti = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            temp_eti = arr[0].eti;
            ans += 1;
            continue;
        }
        if (arr[i].sti >= temp_eti) {
            temp_eti = arr[i].eti;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
