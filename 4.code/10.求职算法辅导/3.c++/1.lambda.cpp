/*************************************************************************
	> File Name: 1.lambda.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月16日 星期六 18时54分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <functional>

using namespace std;

class FUNC {
public:
    FUNC(int x, int &y) : x(x), y(y) {}
    void operator()() {
        x += 1, y += 2;
    }
private:
    int x;
    int &y;
};

int main() {
    int x = 1, y = 2;
    //auto func1 = FUNC(x, y);
    auto func1 = [x, &y]() mutable -> void { x += 1, y += 2;};
    cout << x << " " << y << endl;
    func1();
    cout << x << " " << y << endl;

    function<int(int)> func = [&func](int n) {
        if (n == 1) return 1;
        return func(n - 1) + 2;
    };
    cout << func(9) << endl;
    return 0;
}
