/*************************************************************************
	> File Name: 2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月22日 星期五 17时06分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int num[10] = {0};

void func(int x) {
    int cnt = 0;
    int flag = 0;
    if (x < 0) flag = 1, x = -x;
    while (x) {
        num[cnt++] = x % 2;
        x /= 2;
    }
    if (flag == 0) return ;
    for (int i = 0; i < 7; i++) {
        num[i] = !num[i];
    }
    num[0] += 1;
    for (int i = 0; i < 7; i++) {
        if (num[i] < 2) continue;
        num[i + 1] += num[i] / 2;
        num[i] %= 2;
    }
}

void output() {
    for (int i = 7; i >= 0; i--) {
        cout << num[i];
    }
    return ;
}

int main() {
    int x = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 32; j++) {
            cin >> x;
            func(x);
            output();
            memset(num, 0, sizeof(num));
            if (j % 2 == 0) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
