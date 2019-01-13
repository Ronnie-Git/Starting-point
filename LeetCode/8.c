/*************************************************************************
	> File Name: 8.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 18时27分47秒
 ************************************************************************/

#include <stdio.h>

int atoi(char *str) {
    int i = 0, ret = 0, flag = 1;
    while (str[i] == ' ') ++i;
    if (str[i] == '-') flag = -1, ++i;
    else if (str[i] == '+') flag = 1, ++i;
    while (str[i] && str[i] <= '9' && str[i] >= '0') {
        int pre_ret = ret;
        ret = ret * 10 + (str[i] - '0');
        if (ret / 10 != pre_ret) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }
        ++i;
    }
    return ret * flag;  
}

int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        printf("%d\n", atoi(str));
    }
    return 0;
}
