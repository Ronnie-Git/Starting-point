/*************************************************************************
	> File Name: 4.D.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 09时34分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct arr {
    int n, key;
} arr;

bool cmp(arr a, arr b) {
    return a.key < b.key;
}


int main() {
    int n, flag = 0;
    cin >> n;
    arr num[20];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i].key;
        sum = sum + num[i].key;
        num[i].n = i + 1;
    }
    sort(num, num + n, cmp);
    if (n > 1 && num[0].key != sum - num[0].key) {
        cout << "1 " << num[0].n << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
