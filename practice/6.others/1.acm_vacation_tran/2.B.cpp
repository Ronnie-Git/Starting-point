/*************************************************************************
	> File Name: 2.B.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 08时55分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int num[105] = {0};
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) cin >> num[i];
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (abs(num[j]) > abs(num[j - 1])) swap(num[j], num[j - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
    }
    return 0;
}
