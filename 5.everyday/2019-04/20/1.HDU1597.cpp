/*************************************************************************
	> File Name: 1.HDU1597.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月20日 星期六 09时52分25秒
 ************************************************************************/

#include <iostream>

using namespace std;

typedef long long LL;
const LL MAX_N = 200000; // （MAX_N + 1）* MAX_N / 2 <= 输入的n

// 计算S1 ~ Sn的总数
LL func_exp(LL n) {
	return (n + 1) * n / 2;
}

LL solve(LL n) {
	LL l = 1, r = MAX_N, mid;
    // 类比00001111类型 进行二分查找
	while (l < r) {
		mid = (r + l) / 2;
		if (func_exp(mid) >= n) r = mid;
		else l = mid + 1;
	}
	return (n - (func_exp(l - 1)) - 1) % 9 + 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
