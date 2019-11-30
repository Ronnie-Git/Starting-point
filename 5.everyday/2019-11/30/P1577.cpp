/*************************************************************************
	> File Name: P1577.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Nov 2019 05:49:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 10005
double arr[MAXN];
int n, k;
int check(double x) {
    int cnt = 0;
    for (int i = 0; i < n && cnt < k; i++) {
        cnt += floor(arr[i] / x);
    }
    return (cnt >= k);
}

double solve() {
    double l = 0, r = 10000005.0, mid;
    while (r - l > 1e-4) {
        mid = (l + r) / 2.0;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    double ans = solve();
    char s[100] = {0};
    // 防止四舍五入，两位以后的小数都舍去 
    sprintf(s+1,"%.3f",ans);
    s[strlen(s+1)]='\0';
    printf("%s",s+1);
    return 0;
} 
