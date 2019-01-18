/*************************************************************************
	> File Name: testcase2.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 13时00分29秒
 ************************************************************************/

#ifndef _TESTCASE2_H
#define _TESTCASE2_H
#include "test.h"
#include "add.h"

TEST(test, add_func) {
    EXPECT(add(1, 2), 3);
    EXPECT(add(3, 4), 7);
    EXPECT(add(2, 2), 4);
}

#endif
