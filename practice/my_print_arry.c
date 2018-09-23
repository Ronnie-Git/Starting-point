/*************************************************************************
	> File Name: my_print.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月20日 星期四 20时30分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int64_t temp = va_arg(arg, int);
                        int x[1000], k = 0;
                        if (temp < 0) {
                            putchar('-');
                            temp = (~temp) + 1; // 负数取反加1变正数
                            //temp *= -1;
                        }
                        if (temp == 0) putchar('0'); // temp为0 直接返回 0
                        while (temp) {
                            x[k++] = temp % 10 + '0';
                            temp /= 10;
                        }
                        while (k--) {
                            putchar(x[k]);
                        } 
                    } break;
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
                        exit(1);
                }
            } break;
            default:
                putchar(frm[i]);
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 0);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
