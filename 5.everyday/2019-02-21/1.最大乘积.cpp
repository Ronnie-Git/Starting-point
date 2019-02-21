/*************************************************************************
	> File Name: 1.最大乘机.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月21日 星期四 16时54分13秒
 ************************************************************************/

#include <iostream>
#include <climits>

using namespace std;

int main() {
    long long int x, num[5] = {0};
    int n;
    num[2] = num[3] = num[4] = INT_MIN;
    num[0] = num[1] = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (x > num[4]) {
            num[2] = num[3];
            num[3] = num[4];
            num[4] = x;
        } else if (x > num[3]) {
            num[2] = num[3];
            num[3] = x;
        } else if (x > num[2]) {
            num[2] = x;
        }
        if (x < num[0]) {
            num[1] = num[0];
            num[0] = x;
        } else if (x < num[1]) {
            num[1] = x;
        }
    }
    cout << max(num[0] * num[1] * num[4], num[2] * num[3] * num[4]) << endl;
    return 0;
}
