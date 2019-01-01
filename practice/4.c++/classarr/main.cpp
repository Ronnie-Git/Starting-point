/*************************************************************************
	> File Name: main.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 20时24分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "arr.h"

using namespace std;

int main() {
    srand(time(0));
    Arr arr;
    int val, ans, ind;
    for (int i = 0; i < MAX_N; i++) {
        val = rand() % 1000;
        arr.changeValue(i, val);
    }
    arr.output();
    cout << arr.getLength() << endl;
    
    ind = rand() % MAX_N;
    arr.getValue(ind, ans);
    cout << "getValue() " << ind << ": " << ans << endl;
    
    ind = rand() % MAX_N, val = rand() % 1000;
    arr.changeValue(ind, val);
    cout << "changeValue() " << ind << ": " << val << endl;
    arr.output();
    arr.clean();
    return 0;
}
