/*************************************************************************
	> File Name: 1.shared_ptr.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月24日 星期日 18时30分23秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class A {
public :
    A() {x = 456;}
    virtual int getX() { return this->x; }
    int x;
    virtual ~A() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public :
    B() {x = 789;}
    virtual int getX() { return this->x; }
    int x;
    ~B() {
        cout << "Class B" << endl;
    }
};

class shared_father {
protected :
    static map<void *, int> mp;
};

map<void *, int> shared_father::mp;

template<typename T> 
class my_shared : public shared_father {
public :
    my_shared() : p(nullptr) {}
    my_shared(T *p) : p(p) {
        mp[reinterpret_cast<T *>(p)] += 1;
    }
    template<typename U>
    my_shared<T> &operator=(my_shared<U> &obj) {
        sub_one();
        this->p = obj.get();
        mp[reinterpret_cast<T *>(p)] += 1;
        return *this;
    }
    int use_count() {
        return mp[reinterpret_cast<T *>(p)];
    }
    T *get() { return p; }
    T &operator*() { return *p; }
    T *operator->() { return p; }
    ~my_shared() {
        sub_one();
    }
private:
    void sub_one() {
        if (this->p != nullptr) {
            mp[reinterpret_cast<T *>(p)] -= 1;
            if (mp[reinterpret_cast<T *>(p)] == 0) {
                delete p;
            }
            p = nullptr;
        }
        return ;
    }
    T *p;
};

void func() {
    my_shared<B> p1(new B);
    my_shared<A> p2(new B);
    p2 = p1;
    cout << p1.use_count() << " " << p2.use_count() << endl;
    cout << p1->getX() << endl;
    return ;
}

int main() {
    func();
    cout << "func end";
    return 0;
}

