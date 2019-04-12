/*************************************************************************
	> File Name: 1.最大乘积.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月12日 星期五 21时54分31秒
 ************************************************************************/

#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;

void init(LL *arr) {
    arr[0] = arr[1] = INF;
    arr[2] = arr[3] = arr[4] = -INF - 1;
    return ;
}

int main() {
    LL arr[5] = {0}, x, n;
    init(arr);
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        if (x >= arr[4]) {
            arr[2] = arr[3];
            arr[3] = arr[4];
            arr[4] = x;
        } else if (x >= arr[3]) {
            arr[2] = arr[3];
            arr[3] = x;
        } else if (x >= arr[2]) {
            arr[2] = x;
        }
        if (x <= arr[0]) {
            arr[1] = arr[0];
            arr[0] = x;
        } else if (x <= arr[1]) {
            arr[1] = x;
        }
    }
    cout << max(arr[0] * arr[1] * arr[4], arr[2] * arr[3] * arr[4]);
    return 0;
}
