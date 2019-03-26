/*************************************************************************
	> File Name: 2.替换空格.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 18时31分39秒
 ************************************************************************/

class Solution {
public:
	void replaceSpace(char *str, int length) {
        int n = 0, i = 0;
        while (str[i]) n += (str[i] == ' ') * 2, i++;
        while (i >= 0) {
            if (str[i] == ' ') {
                str[i + n] = '0';
                str[i + n - 1] = '2';
                str[i + n - 2] = '%';
                n -= 2;
            } else {
                str[i + n] = str[i];
            }
            i -= 1;
        }
        return ;
	}
};
