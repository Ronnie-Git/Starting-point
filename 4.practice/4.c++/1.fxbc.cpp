/*************************************************************************
	> File Name: 1.fxbc.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月16日 星期三 15时58分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

#define SWAP(t, a, b) { \
    t (_temp) = (a); (a) = (b); (b) = (_temp); \
}

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void my_swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void my_swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

template <typename T>
void _swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    return ;
}

template <typename T>
void _sort(T *arr, int len) {
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) _swap(arr[j], arr[j - 1]);
        }
    }
    return ;
}

template <typename T>
void print(T *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}

template <typename T1, typename T2, typename T3>
T1 _add(T2 a, T3 b) {
    return static_cast<T1> (a + b);
}

class Test {
public :
    Test(const Test &t) {

    }
public :
    Test() {
        
    }
};

int main() {
    int a = 0, b = 1;
    _swap(a, b);
    cout << a << " " << b << endl;
    Test t1, t2;
    _swap(t1, t2);

    int num[5] = {2, 5, 8, 94, 5};
    string str[5] = {"c", "java", "c++", "python", "c#"};
    _sort(num, 5); // 自动推导参数类型
    _sort(str, 5);
    print<int > (num, 5); // 显式指定参数类型
    print<string >(str, 5);

    int r1 = _add<int>(0.5, 0.3);
    int r2 = _add<int, float>(0.3, 0.6);
    int r3 = _add<int, float, float>(0.5, 0.5);
    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    return 0;
}
