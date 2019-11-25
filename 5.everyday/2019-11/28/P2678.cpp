/*************************************************************************
	> File Name: P2678.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Nov 2019 07:56:04 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 50005

int arr[MAXN];
int e, n, m;

int check(int x) {
    int last = 0, now, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - last < x) {
            if (i == n - 1 || cnt == m) return 0;
            cnt += 1;
        } else {
            last = arr[i];
        }
    }
    return 1;
}

int solve() {
    int l = 0, r = e, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> e >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    arr[n++] = e;
    cout << solve() << endl;
    return 0;
}
