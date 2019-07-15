/*************************************************************************
	> File Name: 1.P1075_质因数分解.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月15日 星期一 19时42分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int MAX_N = 200010;
int prime[MAX_N] = {0};
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}


int main() {
    init();
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= prime[0]; i++) {
        if (n % prime[i] == 0) {
            ans = n / prime[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
