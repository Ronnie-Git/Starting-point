/*************************************************************************
	> File Name: p1146.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月07日 星期五 16时03分01秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, a[200] = {0};
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                cout << a[j];
                continue;
            }
            if (a[j] == 0) a[j] = 1;
            else  a[j] = 0;
            cout << a[j];
        }
        cout << endl;
    }
    return 0;
}
