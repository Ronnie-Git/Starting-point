/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 17时17分27秒
 ************************************************************************/
//全排列函数permutation

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int prime[10] = {2, 3, 5, 7, 11, 13, 17};

long long int check(int *num) {
    long long int temp = 0, ans = 0;
    if (!num[0]) return 0;
    for (int i = 0; i < 7; i++) {
        temp = num[i + 1] * 100 + num[i + 2] * 10  + num[i + 3];//求相邻的三位数
        if (temp % prime[i] != 0) return 0;    
    }
    for (int i = 0; i < 10; i++) ans = ans * 10 + num[i];
    return ans;
}

int main() {
    int num[10] = {0};
    long long int sum = 0, n;
    for (int i = 0; i < 10; i++) num[i] = i;
    do {
        sum += check(num);
    } while (next_permutation(num, num + 10));//全排列函数
    printf("%lld\n", sum);
    return 0;
}
