/*************************************************************************
	> File Name: 1.HDU_3068.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月22日 星期五 14时54分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int Manacher(string temp) {
    string str = "$#";
    for (int i = 0; i < temp.size(); i++) {
        str += temp[i];
        str += "#";
    }
    vector<int> p(str.size(), 0);
    int ans = 0, mx = 0, id = 0;
    for (int i = 1; i < str.size(); i++) {
        p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
        while (str[i + p[i]] == str[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i]);
    }
    return ans - 1;
}

int main() {
    string str;
    while (cin >> str) {
        cout << Manacher(str) << endl;    
    }
    return 0;
}
