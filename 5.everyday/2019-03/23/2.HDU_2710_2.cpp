/*************************************************************************
	> File Name: 1.HDU_2710_2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月23日 星期六 16时46分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

const int LEN = 20005;

int prime[LEN] = {0};

void init_prime() {
    prime[1] = 1;
    for (int i = 2; i <= LEN; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= LEN; j += i) {
            prime[j] = i;
        }
    }
    return ;
}

int main() {
    init_prime();
    int n, x;
    while (cin >> n) {
        int temp = 0, ans = 0;
        while (n--) {
            cin >> x;
            if (prime[x] > temp) {
                temp = prime[x];
                ans = x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
