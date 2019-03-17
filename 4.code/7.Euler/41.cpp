/*************************************************************************
	> File Name: 41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时58分34秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int num[8] = {7, 6, 5, 4, 3, 2, 1};

int is_prime(int x) { // 判断素数
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int ans = 0;
    do {
        int n = 0;
        for (int i = 0; i < 7; i++)  n = n * 10 + num[i];
        if (is_prime(n)) {
            ans = n;
            break;
        }
    } while (prev_permutation(num, num + 7)); // 从大到小全排列
    cout << ans << endl;
    return 0;
}
