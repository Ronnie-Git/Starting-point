/*************************************************************************
	> File Name: main.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 18时52分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include "operation.h"

using namespace std;

int main() {
    Operation op;
    int x, y;
    char k;
    cin >> x >> y;
    cin >> k;
    op.getValue(x, y);
    op.getKey(k);
    cout << op.ans() << endl;
}

