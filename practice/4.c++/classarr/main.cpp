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
    cout << "arr: ";
    arr.output();
    cout << "length = " << arr.getLength() << endl;
    
    ind = rand() % MAX_N;
    arr.getValue(ind, ans);
    cout << "getValue() " << "ind = " << ind << ": " << ans << endl;
    
    ind = rand() % MAX_N, val = rand() % 1000;
    arr.changeValue(ind, val);
    cout << "changeValue() " << "ind = " << ind << ": " << val << endl;
    cout << "arr: ";
    arr.output();

    cout << endl << "Arr test = arr......" << endl;
    Arr test = arr;
    cout << "test: ";
    test.output();
    cout << "length = " << test.getLength() << endl;
    
    ind = rand() % MAX_N;
    test.getValue(ind, ans);
    cout << "getValue() " << "ind = " << ind << ": " << ans << endl;
    
    ind = rand() % MAX_N, val = rand() % 1000;
    test.changeValue(ind, val);
    cout << "changeValue() " << "ind = " << ind << ": " << val << endl;
    cout << "test: ";
    test.output();

    arr.clean();
    test.clean();
    return 0;
}
