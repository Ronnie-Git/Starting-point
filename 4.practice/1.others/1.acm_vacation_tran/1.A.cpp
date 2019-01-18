/*************************************************************************
	> File Name: 1.A.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 08时40分14秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int flag = 0;
        for (int i = n; i <= m; i++) {
            int a = i % 10;
            int b = i / 10 % 10;
            int c = i / 100;
            if (i == a * a * a + b * b * b + c * c * c) {
                if (flag) cout << " ";
                cout << i;
                flag = 1;
            }
        }
        if (!flag) cout << "no";
        cout << endl;
    }
    return 0;
}
