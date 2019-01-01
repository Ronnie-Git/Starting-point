/*************************************************************************
	> File Name: Arr.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 20时17分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include "arr.h"
using namespace std;

Arr::Arr() {
    length = MAX_N;
    data = new int[length];
}

int Arr::getLength() {
    return length;
}

int Arr::getValue(int ind, int &val) {
    if (ind >= length) return 0;
    val = data[ind];
    return 1;
}

int Arr::changeValue(int ind, int val) {
    if (ind >= length) return 0;
    data[ind] = val;
    return 1;
}

void Arr::output() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return ;
}

void Arr::clean() {
    delete[] data;
}
