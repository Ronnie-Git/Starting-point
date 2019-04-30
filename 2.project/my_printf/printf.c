/*************************************************************************
	> File Name: printf.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月30日 星期二 18时13分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>
#include "test.h"

//#define printf(frm, args...) ;

// 数组
int my_printf_int1(int num) {
    unsigned int x = num; 
    if (num < 0) putchar('-'), x = -num;
    int ret = (x == 0 ? 1 : floor(log10(x)) + 1 + (num < 0));
    char temp[20] = {0};
    do {
        temp[++temp[0]] = x % 10 + '0';
        x /= 10;
    } while (x);
    while (temp[0]) {
        putchar(temp[temp[0]--]);
    }
    return ret; 
}

// 倒置
int my_printf_int2(int num) {
    unsigned int x = num;
    if (num < 0) putchar('-'), x = -num;
   
    // 如果 num 为 0，那么 log10(0) 会出错，所以此时将其置为 1
    int ret = (x == 0 ? 1 : floor(log10(x)) + 1 + (num < 0));

    // 防止将数字倒置时越界
    unsigned int temp = 0, digit = 0, dx = x % 10;
    x /= 10;

    while (x) {
        temp = ((temp << 3) + (temp << 1)) + x % 10;
        x /= 10;
        digit += 1;
    }
    while (digit--) {
        putchar(temp % 10 ^ 48); // ^48 可以使 0~9 在数字和字符间相互转换
        temp /= 10;
    }
    putchar(dx + '0');
    return ret;
}

int my_printf(const char *str, ...) {
    va_list args;
    va_start(args, str); // 从 str 后面的参数开始
    int ret = 0;
    while (str[0]) {
        switch (str[0]) {
            case '%': {
                str++;
                switch (str[0]) {
                    case 'd': {
                        int x = va_arg(args, int);
                        ret = my_printf_int1(x);
                        //ret = my_printf_int2(x);
                    } break; 
                } break;
            }
            default : putchar(str[0]), ret++; break;
        }
        str++;
    }
    return ret;
}

int main() {
    test_int();
    return 0;
}
