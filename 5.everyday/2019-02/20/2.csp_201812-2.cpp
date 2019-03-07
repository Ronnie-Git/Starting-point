/*************************************************************************
	> File Name: 2.csp_201812-2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月20日 星期三 16时29分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long int sum = 0;
    int r_num, y_num, g_num, k = 0, t = 0, n;
    cin >> r_num >> y_num >> g_num;
    cin >> n;
    int light_sum = r_num + y_num + g_num;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        if (k == 0) {
            sum += t;
            continue;
        }
        long long int temp = 0;
        switch (k) {
            case 1: temp = (r_num - t + sum) % light_sum; break;
            case 2: temp = (r_num + g_num + y_num - t + sum) % light_sum; break;
            case 3: temp = (r_num + g_num - t + sum) % light_sum; break;
        }
        if (temp >= 0 && temp < r_num) sum += r_num - temp;
        if (temp >= r_num + g_num) sum += light_sum - temp + r_num;
    }
    cout << sum << endl;
    return 0;
}
