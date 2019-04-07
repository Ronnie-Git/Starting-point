/*************************************************************************
	> File Name: 1.整数中1出现的次数.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月07日 星期日 19时03分10秒
 ************************************************************************/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (x) {
                if (x % 10 == 1) ans++;
                x /= 10;
            }
        }
        return ans;
    }
};
