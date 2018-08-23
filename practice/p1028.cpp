/*************************************************************************
	> File Name: p1028.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月23日 星期四 15时08分05秒
 ************************************************************************/

#include<iostream>

using namespace std;
int n;
int a[1010];
int main() {
    cin >> n;
    a[0] = 1, a[1] = 1;
    for (int i = 2; i < 1002; ++i) {
        if (i % 2) {
            a[i] = a[i - 1];
        } else {
            a[i] = a[i - 1] + a[i / 2];
        }
    }
    cout << a[n];
    return 0;
}
