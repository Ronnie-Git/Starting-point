/*************************************************************************
	> File Name: p1012_2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月30日 星期五 18时33分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    string str[25];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }
    printf("\n");
    return 0;
}
