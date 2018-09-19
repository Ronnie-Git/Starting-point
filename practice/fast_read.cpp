/*************************************************************************
	> File Name: fast_read.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月18日 星期二 21时07分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

char ss[1 << 17], *A = ss, *B = ss;
inline char gc() {
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
}
    // A指向头 B指向尾
    // 第一个 A==B 为1 缓冲区里没东西
    // fread
    // 第二个 A==B 为1 没读入东西
    // *A++ 返回A  A移到下一位

    // ss缓冲区数组,B=起始位置＋存入缓冲区的字节
    // fread中是一个整形,逗号表达式＝最后一个表达式的返回值,
    // freadA==B才会返回０表达式的值才会返回１
    // 如果缓冲区内没有数据了进行判断

/*size_t fread ( void *buffer, size_t size, size_t count, FILE **stream*) ;
参 数
buffer 用于接收数据的内存地址
size 要读的每个数据项的字节数，单位是字节
count 要读count个数据项，每个数据项size个字节.
stream 输入流*/

template<typename T> inline void sdf(T &x) {
    char c;
    T y = 1;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1; //找到第一个为字符的位置，如果ｃ＝“－”判断之后处理的是一个负数
    }
    x = c ^ 48;
    while (c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48); // 当c在[48, 57] (c ^ 48) 同 (c - 48) 同 （c - '0'); 相当于x = x * 2 + x * 8 + (c - 48);
    }
    x *= y;
}

int main() {
    int n, a;
    sdf(n); //文件输出
    while (n--) {
        sdf(a);
    }
    return 0;
}
