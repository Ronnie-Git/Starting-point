/*************************************************************************
	> File Name: 22.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 09时42分32秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include "EP22.h"

using namespace std;

int main() {
    int i = 0, sum = 0, ans = 0;
    while (Name[i++].length() != 0); // 计算位数
    sort(Name, Name + i - 1); // 快排 按字典序排序
    for (i = 0; Name[i].length() != 0; i++) {
        for (int j = 0; j < Name[i].length(); j++) {
            ans += (Name[i][j] - 'A' + 1);
        }
        sum += (i + 1) * ans;
        ans = 0;
    }
    printf("%d\n", sum);
}
