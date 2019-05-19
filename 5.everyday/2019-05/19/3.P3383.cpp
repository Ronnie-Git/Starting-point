/*************************************************************************
	> File Name: 3.P3383.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月19日 星期日 10时57分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

bool is_prime(int x) {
    if (x == 1 || x == 0) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 6 != 1 && x % 6 != 5) return 0;
    int temp = sqrt(x);
    for (int i = 5; i <= temp; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        printf("%s\n", (is_prime(x) ? "Yes" : "No"));
    }
    return 0;
}
