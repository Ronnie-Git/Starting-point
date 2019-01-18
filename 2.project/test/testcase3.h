/*************************************************************************
	> File Name: testcase3.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 16时35分58秒
 ************************************************************************/

#ifndef _TESTCASE3_H
#define _TESTCASE3_H
#include <stdio.h>
#include <time.h>
#include "test.h"
#include "sqrt1.h"

TEST(test, sqrt1) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        double x = 1.0 * (rand() % 10000000) / 10000000 * 100000.0;
        EXPECT_lt(sqrt1(x), sqrt(x));
    }
}
#endif
