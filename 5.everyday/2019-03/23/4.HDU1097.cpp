/*************************************************************************
	> File Name: 4.HDU1097.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 17时33分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

int quick_pow(int a, int b){
    int ans = 1, base = a % 10;
    while (b) {
        if (b & 1) ans = ans * base % 10;
        base = (base * base) % 10;
        b >>= 1;
    }
    return ans % 10;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << quick_pow(a, b) << endl;
    }
    return 0;
}
