/*************************************************************************
	> File Name: p1579.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月23日 星期四 15时04分58秒
 ************************************************************************/

#include <iostream>

using namespace std;
int p[30000] = {0}, n[20000];
int x = 0;
int main() {
    int a, f = 0;
    cin >> a;
    p[0] = 1, p[1] = 1;
    for (int i = 2; i < 20000; ++i) {
        if (!p[i]) {
            n[x++] = i;
        }
        for (int j = 0; j < x; ++j) {
            if (n[j] * i > 20000) break;
            p[n[j] * i] = 1;
            if (i % n[j] == 0) break;
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = i; j < x; ++j) {
        	if (n[j] >= a) break;
            if (p[a - n[i] - n[j]] == 0) {
                f = 1;
                cout << n[i] << " " << n[j] << " " << a - n[i] - n[j];
                break;
            }
        }
        if (f) break;
    }
    return 0;
}
