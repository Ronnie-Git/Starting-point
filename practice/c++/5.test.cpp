/*************************************************************************
	> File Name: test4.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月27日 星期四 19时19分13秒
 ************************************************************************/

#include <iostream>

using namespace std;

int g(int a, int b = 5) { // 最少传一个
    return a + b;
}

int add(int a = 1, int b = 0) { // c++中参数可带默认值 
    return a + b;
}

//int add(int a = 3, int b = 0); // c++中参数可带默认值 声明的时候给默认值，定义的时候不能再给默认值

int main() {
    int a = 6, b = 6;
    // 传参的时候从左往右传 都带默认值的 可以传不超过形参个数的实参 
    cout << add() << endl; // 0
    cout << add(1) << endl; // 1
    cout << add(1, 2) << endl; // 3
    cout << g(1, 2) << endl; // 3
    return 0;
}
/*
int add(int a, int b) { // 定义
    return a + b;
}
*/
