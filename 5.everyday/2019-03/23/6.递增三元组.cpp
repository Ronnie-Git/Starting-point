/*************************************************************************
	> File Name: 6.递增三元组.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 14时12分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int SIZE = 100005;

int find_lower(int *num, int n, int key) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (num[mid] < key) l = mid + 1;
        else r = mid;
    }
    return l;
}

int find_upper(int *num, int n, int key) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (num[mid] <= key) l = mid + 1;
        else r = mid;
    }
    return n - l;
}

int main() {
    int n, ans = 0;
    int a[SIZE] = {0}, b[SIZE] = {0}, c[SIZE] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        /*
        int x = find_lower(a, n, b[i]);
        int y = find_upper(c, n, b[i]);
        */
        int x = lower_bound(a, a + n, b[i]) - a;
        int y = n - (upper_bound(c, c + n, b[i]) - c);
        ans += x * y;
    }
    cout << ans << endl;
    return 0;
}
