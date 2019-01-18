/*************************************************************************
	> File Name: test.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月06日 星期六 21时19分18秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <string.h>
int total = 0, expect_cnt = 0;

#define TEST(a, b) void b()

#define EXPECT(func, b) do{\
    total++;\
    if (func == b) {\
        expect_cnt++;\
        printf("%s == %d True\n", #func, b);\
    } else {\
        printf("%s == %d False\n", #func, b);\
    }\
} while(0)

TEST(test, is_prime_func);
TEST(test, add_func);

void ans() {
    if (expect_cnt == total) {
        printf("[ \033[;32;1m PASS\033[0m ] total : %d, expect_cnt : %d\n", total, expect_cnt);
    } else {
        printf("[ \033[;31;1m ERROR\033[0m ] total : %d, expect_cnt : %d\n", total, expect_cnt);
    }
    total = 0, expect_cnt = 0;
}

int RUN_ALL_TEST() {
    printf("[test, is_prime_func]\n");
    is_prime_func();
    ans();

    printf("[test, is_prime_func]\n");
    add_func();
    ans();
    return 0;
}
#endif
