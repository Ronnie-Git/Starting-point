/*************************************************************************
	> File Name: testcase5.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 22时11分34秒
 ************************************************************************/

#ifndef _TESTCASE5_H
#define _TESTCASE5_H
#include <stdio.h>
#include <time.h>
#include "test.h"
#include "quick_pow.h"

TEST(test, quick_pow) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int x = rand() % 9 + 1, y = rand() % 9 + 1;
        EXPECT(quick_pow(x, y), (int)pow(x, y));
    }
}
#endif
