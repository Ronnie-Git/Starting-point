/*************************************************************************
	> File Name: 7.斐波那契数列.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 19时39分37秒
 ************************************************************************/

class Solution {
public:
    Solution() {
        memset(keep, 0, sizeof(keep));
    }
    int keep[50];
    int Fibonacci(int n) {
        if (n <= 1) return n;
        if (keep[n]) return keep[n];
        return (keep[n] = Fibonacci(n - 1) + Fibonacci(n - 2));
    }
};
