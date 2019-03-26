/*************************************************************************
	> File Name: 10.矩形覆盖.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 19时52分18秒
 ************************************************************************/

class Solution {
public:
    Solution() {
        memset(k, 0, sizeof(k));
    }
    int k[60];
    int rectCover(int number) {
        int n = number;
        if (n <= 2) return n;
        if (k[n]) return k[n];
        return (k[n] = rectCover(n - 1) + rectCover(n - 2));
    }
};
