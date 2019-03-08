/*************************************************************************
	> File Name: 1.字符串.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月08日 星期五 20时05分24秒
 ************************************************************************/

#include <iostream>

using namespace std;

int output(char *str) {
    int cnt = 0, i = 0; // cnt记录字符串循环次数
    while (str[i]) {
        if (str[i] == ')') return i;
        
        // 遇到 ( 进入递归
        if (str[i] == '(') {
            if (cnt == 0) cnt = 1; // 有可能()前没数字（猜测）
            int ind = 0;
            for (int j = 0; j < cnt; j++) {
                ind = output(str + i + 1);
            }
            cnt = 0;
            i = i + ind + 2;
            continue;
        }
        
        if (str[i] >= '0' && str[i] <= '9') {
            // 根据题意有可能循环次数不只是一位数，但int能存下
            cnt = cnt * 10 + (str[i] - '0'); 
        } else if (cnt != 0) {
            // 没有() 只循环一个字母
            for (int j = 0; j < cnt; j++) cout << str[i];
            cnt = 0;
        } else {
            cout << str[i];
        }

        i++;
    }
    return i;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char str[10000] = {0};
        cin >> str;
        output(str);
        cout << endl;
    }
    return 0;
}
