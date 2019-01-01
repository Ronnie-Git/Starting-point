/*************************************************************************
	> File Name: operation.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 18时50分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include "operation.h"

using namespace std;

int Operation::getValue(int x, int y) {
    value1 = x;
    value2 = y;
    return 1;
}

int Operation::getKey(char c) {
    key = c;
    return 1;
}

int Operation::ans() {
    if (key == '/' && value2 == 0) return 0;
    switch (key) {
        case '+' : cout << value1 + value2 << endl; break;
        case '-' : cout << value1 - value2 << endl; break;
        case '*' : cout << value1 * value2 << endl; break;
        case '/' : cout << value1 / value2 << endl; break;
        default : return 0;
    }
    return 1;
}
