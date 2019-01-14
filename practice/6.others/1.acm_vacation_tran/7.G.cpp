/*************************************************************************
	> File Name: 7.G.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月14日 星期一 11时41分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    char str1[15] = {0}, str2[15] = {0};
    while (scanf("%d %s %s", &n, str1, str2) != EOF) {
        stack<int> s1;
        int num1[15] = {0}, num2[15] = {0};
        for (int i = 0; str1[i]; i++) num1[i] = str1[i] - '0';
        for (int i = 0; str2[i]; i++) num2[i] = str2[i] - '0';
        int cnt = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            s1.push(num1[i]);
            while (!s1.empty() && s1.top() == num2[cnt]) {
                s1.pop();
                cnt += 1;
            }
        }
        if (cnt != n) {
            cout << "No." << endl << "FINISH" << endl;
            continue;
        }
        stack<int> s2;
        cnt = 0;
        cout << "Yes." << endl;
        for (int i = 0; i < n; i++) {
            s2.push(num1[i]);
            cout << "in" << endl;
            while (!s2.empty() && s2.top() == num2[cnt]) {
                s2.pop();
                cnt += 1;
                cout << "out" << endl;
            }
        }
        cout << "FINISH" << endl;
    }
    return 0;
}
