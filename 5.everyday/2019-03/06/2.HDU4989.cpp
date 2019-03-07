/*************************************************************************
	> File Name: 2.HDU4989.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月06日 星期三 20时40分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
typedef long long LL;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        set<int> s;
        LL sum = 0;
        int num[105] = {0};
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                s.insert(num[i] + num[j]);
            }
        }
        for (auto x : s) {
            sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}
