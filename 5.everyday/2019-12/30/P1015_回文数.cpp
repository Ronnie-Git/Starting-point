/*************************************************************************
	> File Name: P1015_回文数.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Dec 2019 07:48:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 1000
char str[MAXN];
int arr[MAXN];

void get_arr() {
    arr[0] = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            arr[arr[0] - i] = str[i] - 48;
        } else {
            arr[arr[0] - i] = (str[i] - 'A') + 10;
        }
    }
    return ;
}

void add(int base) {
    int iend = arr[0] / 2 + (arr[0] & 1), temp;
    for (int i = 1; i <= iend; i++) {
        temp = arr[i] + arr[arr[0] + 1 - i];
        arr[i] = arr[arr[0] + 1 - i] = temp;
    }
    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] < base) continue;
        arr[i + 1] += arr[i] / base;
        arr[i] %= base;
        arr[0] += (i == arr[0]);
    }
    return ;
}

bool check() {
    int iend = arr[0] / 2 + (arr[0] & 1);
    for (int i = 1; i <= iend; i++) {
        if (arr[i] != arr[arr[0] + 1 - i]) return false;
    }
    return true;
}

int main() {
    int n, cnt = 0, flag = false;
    cin >> n >> str;
    get_arr();
    if (check()) flag = true;
    while (!flag && ++cnt <= 30) {
        add(n);
        if (check()) flag = true;
    }
    if (flag) printf("STEP=%d\n", cnt);
    else printf("Impossible!\n");
    return 0;
}
