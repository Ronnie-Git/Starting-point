/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月05日 星期五 14时40分11秒
 ************************************************************************/

#include "arr.h"

int main() {
    int n, m;
    printf("请选择:\n1.随机生成 2.自行输入\n");
    scanf("%d", &n);
    printf("请输入生成数组的长度：");
    scanf("%d", &m);
    switch (n) {
        case 1: rand_num(m); break;
        case 2: scanf_num(m); break;
    }
    for (int i = 0; i < m; i++) {
        print(a + i);
    }
    printf("\n");
    return 0;
}
