/*************************************************************************
	> File Name: test.h
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月30日 星期二 20时19分48秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include "printf.h"

void test_int() {
    my_printf("hello world : %d\n", 1999999999);
    printf("hello world : %d\n", 1999999999);
    
    my_printf("hello world : %d\n", -5);
    printf("hello world : %d\n", -5);
    
    my_printf("hello world : %d\n", 1000);
    printf("hello world : %d\n", 1000);
    
    my_printf("hello world : %d\n", 0);
    printf("hello world : %d\n", 0);
    
    my_printf("hello world : %d\n", INT_MAX);
    printf("hello world : %d\n", INT_MAX);
    
    my_printf("hello world : %d\n", INT_MIN);
    printf("hello world : %d\n", INT_MIN);

    int n;
    scanf("%d", &n);
    my_printf(" has %d digit\n", my_printf("%d", n));
    printf(" has %d digit\n", printf("%d", n));
    return ;
}

#endif
