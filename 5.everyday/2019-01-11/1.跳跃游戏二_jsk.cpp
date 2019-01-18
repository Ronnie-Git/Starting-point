/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月11日 星期五 10时44分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, flag = 0, ans = 0, cnt = 0;
    int num[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    if (n == 1) flag = 1;
    while (!flag) {
        int temp = 0;
        for (int i = cnt + 1; i <= cnt + num[cnt]; i++) {
            if(i >= n - 1) {
                flag = 1;
                break;
            }
            if (i + num[i] > temp + num[temp]) temp = i;
        }
        ans += 1;
        cnt = temp;
    }
    cout << ans << endl;
    return 0;
}
