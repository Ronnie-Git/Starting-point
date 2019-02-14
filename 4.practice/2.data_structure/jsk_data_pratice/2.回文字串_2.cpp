/*************************************************************************
	> File Name: 2.回文字串_2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 15时25分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void expand(char *str, int i, int j, int n) {
    while (i >= 0 && j < n && str[i] == str[j]) {
        char c = str[j + 1];
        str[j + 1] = 0;
        cout << str + i << endl;
        str[j + 1] = c;
        i--, j++;
    }
    return ;
}

int main() {
    char str[10000] = {0};
    cin >> str;
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        expand(str, i, i, len);
        expand(str, i, i + 1, len);
    }
    return 0;
}
