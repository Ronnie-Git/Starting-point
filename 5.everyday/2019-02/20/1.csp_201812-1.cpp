/*************************************************************************
	> File Name: csp_201812-1.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月20日 星期三 16时06分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int sum = 0, n = 0;
    int r_num, y_num, g_num, k = 0, t = 0;
    cin >> r_num >> y_num >> g_num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        if (k == 3) continue;
        if (k == 2) sum += r_num;
        sum += t;
    }
    cout << sum << endl;
    return 0;
}
