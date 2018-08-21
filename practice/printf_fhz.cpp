/*************************************************************************
	> File Name: lx.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月21日 星期二 09时44分19秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    char str[100] = {0};
    for (int i = 0; i < 3; i++) {
        strcat(str, "%d");
    }
    strcat(str, "\n");
    int a = 5, b = 4, c = 3;
    printf("%s", str);
    printf(str, a, b, c);
    printf("%d", printf(str, a, b, c)); // printf返回值输出字符的数量
    return 0;
}
