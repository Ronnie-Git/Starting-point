/*************************************************************************
	> File Name: f.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Nov 2019 07:43:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int p, q;
    while (cin >> p >> q) {
        cout << p + q - gcd(p, q) << endl;
    }
    return 0;
}
