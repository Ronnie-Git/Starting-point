/*************************************************************************
	> File Name: arr_func.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月05日 星期五 16时25分25秒
 ************************************************************************/

#ifndef _ARR_FUNC_H
#define _ARR_FUNC_H

// 输出函数 传入的参数为结构体
void print(arr);

// 输入函数 传入的参数为数组长度
void scanf_num(int);

// 随机生成数函数 传入的参数为数组长度
void rand_num(int);

// 将数据赋值给结构体 传入的参数为结构体，整型数据
void set(arr, int);

// 将数据赋值给结构体 传入的参数为结构体，双精度型数据
void set(arr, double);

// 将数据赋值给结构体 传入的参数为结构体，单精度型数据
void set(arr, float);

// 将数据赋值给结构体 传入的参数为结构体，字符型数据
void set(arr, char);

// 将数据赋值给结构体 传入的参数为结构体，long long 型数据
void set(arr, long long int);

#endif
