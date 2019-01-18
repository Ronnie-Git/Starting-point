/*************************************************************************
	> File Name: 11.test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 19时54分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

class Test {
private :
    int a;
    int *p;
public :
    Test() {
        p = new int(1);
    }
    Test(int value) {
        a = value;
        p = new int(1);
        cout << "Test(int) " << a << endl;
    }
    Test(const Test &obj) {
        a = obj.a;
        p = new int;
        *p = *obj.p;
    }
    int getA() {
        return a;
    }
    int *getP() {
        return p;
    }
    int get() {
        return *p;
    }
    void free() {
        delete p;
    }
};

int main() {
    // 1 new
    Test *p = new Test(1);
    Test t3(1);
    Test t5 = t3;
    // 2 对象数组
    cout << "t3: " << t3.get() << " &t3 : " << t3.getP() << endl;
    cout << "t5: " << t5.get() << " &t5 : " << t5.getP() << endl;
    Test t[3] = {Test(), Test(2), Test(3)};
    for (int i = 0; i < 3; i++) {
        cout << t[i].getA() << endl;
    }
    t3.free();
    t5.free();
    delete p;
    return 0;
}
