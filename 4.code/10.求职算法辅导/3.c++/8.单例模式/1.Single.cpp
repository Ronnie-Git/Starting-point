/*************************************************************************
	> File Name: 1.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月24日 星期日 19时25分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

class SingleClass {
public :
    int getX() { return x; }

    static SingleClass *get() {
        if (SingleClass::obj == nullptr) {
            obj = new SingleClass();
        }
        return obj;
    }
private :
    int x;
    static SingleClass *obj;
    SingleClass() { x = 234; }
    SingleClass(const SingleClass &obj) {}
};

SingleClass *SingleClass::obj = nullptr;

int main() {
    SingleClass *p1 = SingleClass::get();
    SingleClass *p2 = SingleClass::get();
    cout << p1 << " " << p2 << endl;
    cout << p1->getX() << " " << p2->getX() << endl;
    SingleClass::get()->getX();
    return 0;
}
