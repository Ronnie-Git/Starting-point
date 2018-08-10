/*************************************************************************
	> File Name: 24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 09时59分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include "EP42.h"

using namespace std;

int three(int n) { // 计算三角形数
    return (n * (n + 1) / 2);
}

int check(int x) { // 查找三角形数
    int left = 1, right = 10000, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (three(mid) == x) return 1;
        if (three(mid) > x) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}
int main() {
    int i = 0, k = 0;
    while (str[i].length() != 0) {
        int sum = 0;
        for (int j = 0; j < str[i].length(); j++) { // 求字符串权
            sum += (str[i][j] - 'A') + 1;
        }
        i++;
        if (check(sum)) k++;
    }
    printf("%d\n", k);
    return 0;
}
