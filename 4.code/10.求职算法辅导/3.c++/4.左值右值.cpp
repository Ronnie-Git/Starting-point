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

        vector(vector<T> &&arr) {
            this->data = arr.data;
            this->size = arr.size;
            arr.data = nullptr;
            arr.size = 0;
        }

        T &operator[](int ind) {
            return this->data[ind];
        }

    private :
        T *data;
        int size;
    };

    void print(int &a) {
        cout << "print left value " << a << endl;
    }

    void print(int &&a) {
        cout << "print right value " << a << endl;
    }

    int value_type(int &a) {
        cout << "left value " << a << endl;
        print(a);
        return 1;
    }

    int value_type(int &&a) {
        cout << "right value " << a << endl;
        print(a);
        print(std::forward<int &&> (a));
        print(std::move(a));
        return 1;
    }


    int test() {
        int a = 9973;
        int &b = a;
        value_type(a);
        value_type(3 + 5);
        return 0;
    }
}

int main() {
    my::test();
    return 0;
}
