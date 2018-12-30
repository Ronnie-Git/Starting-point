/*************************************************************************
	> File Name: test.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月07日 星期日 11时36分06秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <stdlib.h>

struct TestFuncData {
    int total, expect;
};

typedef void (*test_fucn_t)();
struct FuncData {
    const char *a_str, *b_str;
    test_fucn_t func;               
    struct FuncData *next;         
};

struct FuncData *FuncData_head = NULL; 

struct FuncData *getFuncData(
    const char *a, 
    const char *b,
    test_fucn_t func,
    struct FuncData *next
) {
    struct FuncData *p = (struct FuncData *) malloc (sizeof(struct FuncData));
    p->a_str = a;
    p->b_str = b;
    p->func = func;
    p->next = next;
    return p;
}

#define TEST(a, b) \
    void a##_haizeix_##b(struct TestFuncData *);\
    __attribute__((constructor))\
    void ADDFUNC_##a##_haizeix_##b(){ \
        FuncData_head = getFuncData(#a, #b, a##_haizeix_##b, FuncData_head); \
    } \
    void a##_haizeix_##b(struct TestFuncData *__data) 

#define EXPECT(a, b) ({ \
    int temp; \
    printf("%s = %s %s\n", #a, #b, (temp = (a == b)) ? "True" : "False");\
    __data->total += 1;\
    __data->expect += temp;\
})

int RUN_ALL_TEST() {
    struct FuncData ret;
    ret.next = NULL;
    for(struct FuncData *p = FuncData_head, *q; p; p = q) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
    }
    FuncData_head = ret.next;
    char color[3][100] = {
        "[ \033[1;32m%.2lf%% \033[0m] total = %d  expect = %d\n",
        "[ \033[0;31m%.2lf%% \033[0m] total = %d  expect = %d\n",
        "[ \033[1;31m%.2lf%% \033[0m] total = %d  expect = %d\n",
    };
    for(struct FuncData *p = FuncData_head; p; p = p -> next) {
        struct TestFuncData data = {0,0};
        printf("[%s %s]\n", p->a_str, p->b_str);
        p->func(&data);
        double rate = 1.0 * data.expect / data.total * 100;
        int ind = 0;
        if (rate < 100) ind = 1;
        if (rate < 50) ind = 2;
        printf(color[ind], rate, data.total, data.expect);
    }
    return 0;
}
#endif
