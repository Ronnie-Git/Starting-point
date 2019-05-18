/*************************************************************************
	> File Name: 1.P1403.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年05月18日 星期六 08时51分11秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1000005

int dnum[MAX_N + 5] = {0}; 
int mnum[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};

void init() {
    dnum[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1; 
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}

int main() {
    init();
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += dnum[i];
    }
    cout << ans << endl;
    return 0;
}
