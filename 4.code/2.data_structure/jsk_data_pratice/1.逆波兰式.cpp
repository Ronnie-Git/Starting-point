/*************************************************************************
	> File Name: 1.nbls.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 15时00分55秒
 ************************************************************************/

// 将表达式分块 通过加减法将乘除法的表达式分成多个部分 每个乘除法的表达式都当成一个单元
// getNum 获得数字
// getTerm 处理乘法除法
// calc 处理加减法

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;

int getNum(char *str, int *ret) {
    int i = 0, num = 0;
    while (str[i] <= '9' && str[i] >= '0') {
        num = num * 10 + str[i++] - '0';
    }
    *ret = num;
    return i;
}

int getTerm(char *str, int *ret) { // 处理乘法除法
    int i = 0, temp;
    if (str[i] == 0) return 0;
    i += getNum(str + i, ret); // 先获得一个数字
    if (str[i] == 0) return i; // 如果到结尾返回处理了多少个字符
    while (str[i]) { // 同级优先级顺序计算
        switch (str[i]) {
            case '*' :  {
                i += getNum(str + i + 1, &temp) + 1; // 计算本层处理了多少个字符 +1表示本层符号位
                (*ret) *= temp;
            } break;
            case '/' : {
                i += getNum(str + i + 1, &temp) + 1;
                (*ret) /= temp;
            } break;
            default : return i;
        }
    }
    return i;
}

int calc(char *str) { // 给我们一个表达式并计算值处理加减法
    int i = 0, a, b;
    char op;
    if (str[i] == 0) return 0;
    i += getTerm(str + i, &a); // 处理乘法除法
    if (str[i] == 0) return a;
    while (str[i]) { // 同级优先级顺序计算
        op = str[i];
        i += getTerm(str + i + 1, &b) + 1;
        switch (op) {
            case '+' :  a += b; break;
            case '-' :  a -= b; break;
        }
    }
    return a;
}

int main() {
    char str[1000];
    scanf("%s", str);
    printf("%d\n", calc(str));
    return 0;
}
