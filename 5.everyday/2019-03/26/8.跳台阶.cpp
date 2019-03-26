/*************************************************************************
	> File Name: 8.跳台阶.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 19时47分01秒
 ************************************************************************/

class Solution {
public:
    Solution() {
        memset(keep, 0, sizeof(keep));
    }
    int keep[100];
    int jumpFloor(int number) {
        int n = number;
        if (n <= 1) return 1;
        if (keep[n]) return keep[n];
        return (keep[n] = jumpFloor(n - 1) + jumpFloor(n - 2));
    }
};
