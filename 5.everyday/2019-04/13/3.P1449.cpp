/*************************************************************************
	> File Name: 1.P1449.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年04月13日 星期六 10时11分43秒
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

typedef long long LL;

int main() {
    stack<LL> s;
    char c;
    while (cin >> c) {
        if (c == '@') break;
        if (c >= '0' && c <= '9') {
            LL num = c - '0';
            while (cin >> c) {
                if (c == '.') break;
                num = num * 10 + (c - '0');
            }
            s.push(num);
            continue;
        }
        LL a = s.top();
        s.pop();
        LL b = s.top();
        s.pop();
        switch (c) {
            case '-': s.push(b - a); break;
            case '+': s.push(a + b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(b / a); break;
        }
    }
    cout << s.top() << endl;
    s.pop();
    return 0;
}
