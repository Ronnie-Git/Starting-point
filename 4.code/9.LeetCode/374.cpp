/*************************************************************************
	> File Name: 374.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月09日 星期五 19时19分44秒
 ************************************************************************/

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            int k = guess(mid);
            if (!k) return mid;
            if (k == 1) l = mid + 1;
            else r = mid - 1;
        }
        return 0;
    }
};
