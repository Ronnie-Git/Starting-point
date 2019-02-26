/*************************************************************************
	> File Name: 3.解方程.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月25日 星期一 20时29分03秒
 ************************************************************************/

// 注意边界精度，输出结果保留10位小数

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

double getY(double x) {
    return (x * x * x * x + 5 * x * x * x + 6 * x * x + 7 * x + 4);
}

double solve_equation(double y) {
    double l = 0, r = 100.0, mid;
    while (r - l > 1e-11) {
        mid = (l + r) / 2.0;
        if (y - getY(mid) > 0) l = mid;
        else r = mid;
    }
    return (fabs(y - getY(mid)) < 1e-3 ? mid : -1);
}

int main() {
    double y;
    cin >> y;
    cout << setiosflags(ios::fixed) << setprecision(10) << solve_equation(y) << endl; 
    return 0;
}
