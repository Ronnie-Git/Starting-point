/*************************************************************************
	> File Name: test.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 11时40分38秒
 ************************************************************************/

#include <stdio.h>
#include "is_prime.h"
#include "add.h"
#include "sqrt1.h"
#include "test.h"
#ifdef TEST_FUNC
    #include "testcase1.h"
    #include "testcase2.h"
    #include "testcase3.h"
    #include "testcase4.h"
    #include "testcase5.h"
#endif

int main() {
    printf("hello world\n\n");
    return RUN_ALL_TEST();
}
