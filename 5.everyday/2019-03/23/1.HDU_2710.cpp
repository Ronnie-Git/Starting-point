/*************************************************************************
	> File Name: HDU_2710.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 16时02分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int LEN = 20005;

int prime[LEN] = {0};

void init_prime() {
    for (int i = 2; i <= LEN; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= LEN; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    int n, x;
    init_prime();
    while (cin >> n) {
        int ans = 1, temp = 1;
        while (n--) {
            cin >> x;
            for (int i = prime[0]; i >= 1; i--) {
                if (x % prime[i] == 0) {
                    if (prime[i] > temp) {
                        temp = prime[i];
                        ans = x;
                    }
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
