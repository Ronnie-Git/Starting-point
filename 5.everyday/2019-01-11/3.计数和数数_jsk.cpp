/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月11日 星期五 14时14分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string num = "1";
        while (--n) {
            string temp;
            int cnt = 1;
            char c = num[0];
            for (int i = 1; i <= num.length(); i++) {
                if (c == num[i]) {
                    cnt += 1;
                    continue;
                }
                temp += (cnt + '0');
                temp += c;
                c = num[i];
                cnt = 1;
            }
            num = temp;
        }
        cout << num << endl;
    }
    return 0;
}
