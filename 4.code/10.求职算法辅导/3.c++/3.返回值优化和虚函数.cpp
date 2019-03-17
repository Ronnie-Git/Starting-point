/*************************************************************************
	> File Name: 1.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月17日 星期日 18时24分52秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace my {
    template<typename T>
    class vector {
    public :
        vector() {
            this->data = new T[10];
            this->size = 10;
        }
        vector(const vector<T> &arr) : data(nullptr), size(0) {
            cout << "copy" << endl;
            if (this->data) {
                delete[] this->data;
            }
            this->data = new T[arr.size];
            this->size = arr.size;
            for (int i = 0; i < this->size; i++) {
                new(this->data + i) T(arr.data[i]);
            }
        }
        T &operator[](int ind) {
            return this->data[ind];
        }

    private :
        T *data;
        int size;
    };

    vector<int> func() {
        vector<int> temp;
        temp[4] = 5678;
        return temp;
    }

    class A {
    public:
        virtual void test(int x) {
            cout << "bye bye" << endl;
            cout << x << endl;
        }
        void test1() {
            cout << "bye bye" << endl;
        }
    };

    class B : public A {
    public:
        //virtual void test(B* this, int x) {}
        virtual void test(int x) {
            cout << "my name is B" << endl;
            cout << this << endl;
            cout << x << endl;
        }
        void test1() {
            cout << "my name is B" << endl;
        }
    };
    typedef void (*FUNC)(void *, int);
    int test() {
        B b;
        A *p = &b;
        b.test(5);
        /*
        b.test();
        b.test1();
        p->test();
        p->test1();
        */

        ((FUNC**)(&b))[0][0](&b, 5);

        vector<int> d(func()); 
        // 不会调用拷贝构造，达到返回值优化的效果
        cout << d[4] << endl;
        /*
        my::vector<my::vector<int> > a;
        a[5][5] = 16384;
        my::vector<my::vector<int> > c(a);
        cout << (c[5][5] == a[5][5]) << endl;
        c[5][5] = 16;
        c[5][5] = 16;
        cout << (c[5][5] != a[5][5]) << endl;
        */
        return 0;
    }
}

/*
void func(int x) {}
void func(char *x) {}
*/

int main() {
    //func(nullptr);
    /*
    my::vector<int> a;
    for (int i = 0; i < 5; i++)  {
        a[i] = i;
    }
    my::vector<int> c(a);
    for (int i = 0; i < 5; i++) cout << c[i] << endl;
    */
    /*
    my::vector<my::vector<int> > a;
    a[5][5] = 16384;
    my::vector<my::vector<int> > c(a);
    cout << (c[5][5] == a[5][5]) << endl;
    c[5][5] = 16;
    cout << (c[5][5] != a[5][5]) << endl;
    */
    my::test();
    return 0;
}
