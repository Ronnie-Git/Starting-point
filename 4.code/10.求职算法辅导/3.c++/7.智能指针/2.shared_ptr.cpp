/*************************************************************************
	> File Name: 2.shared_ptr.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月24日 星期日 18时30分59秒
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


namespace my {
template<typename T>
    class shared_ptr {
    public :
        shared_ptr() : p(nullptr), cnt(nullptr) {}
        shared_ptr(T *p) : p(p), cnt(nullptr) {
            cnt = new size_t(1);
        }
        shared_ptr(const shared_ptr<T> &obj) : p(p), cnt(cnt) {
            (*cnt) += 1;
        }
        shared_ptr(shared_ptr<T> &&obj) : p(p), cnt(cnt) { 
            obj.p = nullptr; 
            obj.cnt = nullptr;
        }
        size_t &use_count() { return (*cnt); }
        T *get() { return p; }
        T &operator*() { return *p; }
        T *operator->() { return p; }
        template<typename U>
        shared_ptr<T> &operator=(shared_ptr<U> &obj) {
            sub_one();
            p = reinterpret_cast<T *>(obj.get());
            cnt = &(obj.use_count());
            (*cnt) += 1;
            return *this;
        }
        ~shared_ptr() {
            sub_one();
        }
    private:
        void sub_one() {
            if (p == nullptr) return ;
            (*cnt) -= 1;
            if ((*cnt) == 0) {
                delete cnt;
                delete p;
                cnt = nullptr;
            }
            p = nullptr;
        }
        T *p;
        size_t *cnt;
    };
}

class A {
public :
    A() {}
    virtual ~A() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public :
    B() {}
    virtual ~B() {
        cout << "Class B" << endl;
    }
};

void func() {
    my::shared_ptr<A> p(new B);
    B *temp_q = dynamic_cast<B *>(p.get());
    my::shared_ptr<B> q(temp_q);
    cout << p.use_count() << " " << q.use_count() << endl;
    return ;
}

int main() {
    func();
    return 0;
}

