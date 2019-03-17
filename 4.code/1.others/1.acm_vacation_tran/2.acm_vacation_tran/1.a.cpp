/*************************************************************************
	> File Name: 1.a.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月01日 星期五 11时51分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, m;
double num[10005] = {0};
int check(double x) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp = (int)(num[i] / x);
        if (temp == 0 || sum >= m + 1) break;
        sum += temp;
    }
    return (sum >= m + 1);
}

double solve(double l, double r) {
    double mid;
    const double EPS = 1e-6;
    while (r - l > EPS) {
        mid = (l + r) / 2.0;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return mid;
}

bool cmp(double x, double y) {
    return x > y;
}

int main() {
    const double pi = acos(-1.0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            num[i] = num[i] * num[i] * pi;
        }
        sort(num, num + n, cmp);
        printf("%.4lf\n", solve(0.0, num[0]));
    }
    return 0;
}
