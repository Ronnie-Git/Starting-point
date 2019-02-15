/*************************************************************************
	> File Name: 10.test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月21日 星期一 18时22分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

class Test {
private :
    int i;
public :
    Test(int v = 0) : i(v) {
    }
    int getI() {
        return i;
    }
};

template<typename T>
class SmartPoint {
private :
    T *mp;
public :
    SmartPoint(T *p = NULL) {
        mp = p;
    }
    SmartPoint(const SmartPoint &obj) {
        mp = obj.mp;
        const_cast<SmartPoint &>(obj).mp = NULL;
    }
    Test *operator->() {
        return mp;
    }
    Test &operator*() {
        return *mp;
    }
    SmartPoint &operator=(const SmartPoint &obj) {
        if (this != &obj) { // 防止自赋值
            delete mp;
            mp = obj.mp;
            const_cast<SmartPoint &>(obj).mp = NULL;
        }
        return *this;
    }
    ~SmartPoint() {
        cout << "~SmartPoint" << endl;
        delete mp;
    }
};

int main() {
    for (int i = 0; i < 5; i++) {
        SmartPoint<Test> p = new Test(i);
        cout << p->getI() << endl;
    }
    SmartPoint<Test> p1(new Test);
    SmartPoint<Test> p2(new Test);
    return 0;
}
