/*************************************************************************
	> File Name: testcase1.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 12时59分47秒
 ************************************************************************/

#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "test.h"
#include "is_prime.h"

TEST(test, is_prime_func) {
    EXPECT(is_prime(2), 0);
    EXPECT(is_prime(-2), 0);
    EXPECT(is_prime(15), 0);
    EXPECT(is_prime(9973), 1);
}

#endif
