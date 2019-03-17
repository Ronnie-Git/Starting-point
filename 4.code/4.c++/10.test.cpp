/*************************************************************************
	> File Name: 9.test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 19时22分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

/*
全局区没初始化 系统会初始化为0
栈区堆区没初始化 会是随机值
 */

class Test {
private :
    int a;
public :
    Test() {
        a = 10;
        cout << "Test() " << a << endl;
    }
    Test(int value) {
        a = value;
        cout << "Test(int) " << a << endl;
    }
    int getA() {
        return a;
    }
};

int main() {
    Test t(1);
    Test t2 = 100;
    Test t3; // 无参的构造函数只能这么用; 如果 Test t3(); 这样定义会被理解为函数的声明
    cout << t3.getA() << endl;
    return 0;
}
