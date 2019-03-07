/*************************************************************************
	> File Name: 1.P5082.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月19日 星期六 11时52分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n; 
    long long x, sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum1 += x;
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum2 += x;
    }
    printf("%.6lf\n", (sum1 * 3 - sum2 * 2) * 1.0 / (sum1 - sum2));
    return 0;
}
