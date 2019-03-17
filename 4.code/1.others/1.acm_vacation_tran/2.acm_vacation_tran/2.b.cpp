/*************************************************************************
	> File Name: 2.b.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月01日 星期五 10时58分04秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX_N 100000000 

using namespace std;

void init(int *num) {
    num[1] = 1;
    num[2] = 3;
    for(int i = 3; i < 65; i++) {
        int min_temp = MAX_N;
        for (int j = 1; j < i; j++) {
            if (2 * num[j] + pow(2.0, i - j) - 1 < min_temp) {
                min_temp = 2 * num[j] + pow(2.0, i - j) - 1;
            }
        }
        num[i] = min_temp;
    }
    return ;
}

int main() {
    int num[100] = {0}, n;
    init(num);
    while(scanf("%d", &n) != EOF) {
        cout << num[n] << endl;
    }
    return 0;
}

