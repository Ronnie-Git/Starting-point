/*************************************************************************
	> File Name: 1.HDU1075.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月09日 星期六 18时33分49秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
    string cmd, str;
    map<string, string> m;
    cin >> cmd;
    while (cin >> cmd) {
        if (cmd == "END") break;
        cin >> str;
        m[str] = cmd;
    }
    cin >> cmd;
    getline(cin, cmd);
    while (getline(cin, str)) {
        if (str == "END") break;
        string temp;
        for (auto x : str) {
            if (x >= 'a' && x <= 'z') {
                temp += x;
            } else {
                cout << (m.count(temp) ? m[temp] : temp) << x;
                temp.clear();
            }
        }
        cout << endl;
    }
    return 0;
}
