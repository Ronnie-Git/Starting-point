/*************************************************************************
	> File Name: 2.回文字串.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 15时19分09秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int is_valid(char *str, int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--]) return 0;
    }
    return 1;
}

int main() {
    char str[10000] = {0};
    cin >> str;
    for  (int i = 0; str[i]; i++) {
        for (int j = i; str[j]; j++) {
            if (is_valid(str, i, j)) {
                char c = str[j + 1];
                str[j + 1] = 0;
                cout << str + i << endl;
                str[j + 1] = c;
            }
        }
    }
    return 0;
}
