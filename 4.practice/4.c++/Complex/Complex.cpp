/*************************************************************************
	> File Name: Complex.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月18日 星期五 16时20分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class Complex {
private :
    double real;
    double imag;
public :
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }
    double getR() {
        return this->real;
    }
    double getI() {
        return this->imag;
    }
    Complex operator+(const Complex &c2);
    Complex operator-(const Complex &c2);
    Complex operator*(const Complex &c2);
    Complex operator/(const Complex &c2);
    bool operator==(const Complex &c2);
    bool operator!=(const Complex &c2);
    //Complex& operator+(Complex &c2);
    Complex& operator=(const Complex &c1) {
        if (this != &c1) { // 不允许自赋值 a = a
            this->real = c1.real;
            this->imag = c1.imag;
        }
        return *this;
    }
};

Complex Complex::operator+(const Complex &c2) {
    Complex ret;
    ret.real = this->real + c2.real;
    ret.imag = this->imag + c2.imag;
    return ret;
}

/*
// 重载= 不用const 可用Complex&
Complex& Complex::operator+(Complex &c2) {
    Complex *ret;
    ret->real = this->real + c2.real;
    ret->imag = this->imag + c2.imag;
    return *ret;
}
*/

Complex Complex::operator-(const Complex &c2) {
    Complex ret;
    ret.real = this->real - c2.real;
    ret.imag = this->imag - c2.imag;
    return ret;
}

Complex Complex::operator*(const Complex &c2) {
    Complex ret;
    ret.real = this->real * c2.real - this->imag * c2.imag;
    ret.imag = this->real * c2.imag + this->imag * c2.real;
    return ret;
}

Complex Complex::operator/(const Complex &c2) {
    Complex ret;
    double temp = c2.real * c2.real + c2.imag * c2.imag;
    ret.real = (this->real * c2.real + this->imag * c2.imag) / temp;
    ret.imag = (this->real * c2.imag - this->imag * c2.real) / temp;
    return ret;
}

bool Complex::operator==(const Complex &c2) {
    const double key = 1e-7;
    return (fabs(this->real - c2.real) < key && fabs(this->imag - c2.imag) < key);
}

bool Complex::operator!=(const Complex &c2) {
    return !(this->operator==(c2));
}

int main() {
    Complex c1(1, 2);
    Complex c2(2, 3);
    Complex c3;
    c3 = c1 + c2;
    //c3 = c1.operator+(c2);
    cout << "c1 + c2 = " << c3.getR() << " + " << "(" << c3.getI() << "i)" << endl;
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3.getR() << " + " << "(" << c3.getI() << "i)" << endl;
    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3.getR() << " + " << "(" << c3.getI() << "i)" << endl;
    c3 = c1 / c2;
    cout << "c1 / c2 = " << c3.getR() << " + " << "(" << c3.getI() << "i)" << endl;
    cout << "c1 == c2 " << ((c1 == c2) ? "True" : "Fale") << endl;
    cout << "c1 != c2 " << ((c1 != c2) ? "True" : "Fale") << endl;

    Complex c4(1, 3);
    (c4 = c3) = c2;
    cout << c4.getR() << " + " << c4.getI() << "i" << endl;
    return 0;
}
