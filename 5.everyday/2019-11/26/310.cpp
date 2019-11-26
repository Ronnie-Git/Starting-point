/*************************************************************************
	> File Name: 310.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Nov 2019 07:30:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAXN 1000005
int prime[MAXN];

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] < MAXN; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    int n;
    init();
    cin >> n;
    for (int i = 1; i <= prime[0] && prime[i] <= n; i++) {
        int ans = 0, temp = n;
        while (temp) {
            ans += temp / prime[i];
            temp /= prime[i];
        }
        cout << prime[i] << " " << ans << endl;
    }
    return 0;
}
