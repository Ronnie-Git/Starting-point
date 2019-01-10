/*************************************************************************
	> File Name: main.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月10日 星期四 20时34分51秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int main() {
    demo *p = demo_init(1, 2);
    printf("a = %d\n", getI(p));
    printf("b = %d\n", getJ(p));
    printf("add = %d\n", add(p, 5));
    return 0;
}
