/*************************************************************************
	> File Name: 3.乘积尾零.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月22日 星期五 17时43分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int x, cnt_2 = 0, cnt_5 = 0;
    while (cin >> x) {
        while (x) {
            if (x % 2) break;
            ++cnt_2;
            x /= 2;
        }
        while (x) {
            if (x % 5) break; 
            ++cnt_5;
            x /= 5;
        }
    }
    cout << min(cnt_2, cnt_5) << endl;
    return 0;
}
