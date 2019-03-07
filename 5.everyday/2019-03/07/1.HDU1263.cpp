/*************************************************************************
	> File Name: 1.HDU1263.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月07日 星期四 20时47分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() {
    int t, n, num;
    string name_f, name_p;
    cin >> t;
    while (t--) {
        cin >> n;
        map<string, map<string, int> > m;
        for (int i = 0; i < n; i++) {
            cin >> name_f >> name_p >> num;
            m[name_p][name_f] += num;
        }
        for (auto x : m) {
            cout << x.first << endl;
            for (auto y : x.second) {
                cout << "   |----" << y.first << "(" << y.second << ")" << endl;
            }
        }
        if (t) cout << endl;
    }
    return 0;
}
