/*************************************************************************
	> File Name: 5.test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月08日 星期二 19时52分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

class Father {
protected :
    int i;
public :
    Father() {
        i = 100;
    }
    int get() {
        return i;
    }
    virtual void say() { // 虚函数
        cout << "I'm Father." << endl;
    }
};

class Son : public Father {
private :
    int age;
public :
    int getAge() {
        return age;
    }
    int add(int v) {
        age = v + i;
        return age;
    }
    void say() {
        cout << "I'm Son." << endl;
    }
};

void how_to_say(Father *f) {
    f->say();
}

int main() {
    Father f;
    Son s;
    cout << s.get() << endl;
    cout << s.getAge() << endl;
    how_to_say(&f);
    how_to_say(&s);
    return 0;
}
