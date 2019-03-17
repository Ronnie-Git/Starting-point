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

Arr::Arr(const Arr &obj) {
    length = obj.length;
    data = new int[obj.length];
    for (int i = 0; i < obj.length; i++) {
        data[i] = obj.data[i];
    }
}

int Arr::getLength() {
    return length;
}

bool Arr::getValue(int ind, int &val) {
    if (ind >= length || ind < 0) return false;
    val = data[ind];
    return true;
}

bool Arr::changeValue(int ind, int val) {
    if (ind >= length || ind < 0) return false;
    data[ind] = val;
    return true;
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
