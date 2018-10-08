/*************************************************************************
	> File Name: testcase4.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 21时39分11秒
 ************************************************************************/

#ifndef _TESTCASE4_H
#define _TESTCASE4_H
#include <stdio.h>
#include <time.h>
#include "test.h"
#include "newton.h"

TEST(test, newton) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        double x = 1.0 * (rand() % 10000000) / 10000000 * 100000.0;
        EXPECT_lt(newton(x), sqrt(x));
    }
}
#endif
