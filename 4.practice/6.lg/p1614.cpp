/*************************************************************************
	> File Name: p1614.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月09日 星期日 11时45分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX_N 10000000

using namespace std;

int num[3005] = {0};

int main() {
    int n, m, sum = 0, ans = MAX_N;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum += num[i];
        if (i >= m) {
            ans = min(sum, ans);
            sum -= num[i - m + 1];
        }
    }
    m ? cout << ans << endl : cout << "0" << endl;
    return 0;
} 
