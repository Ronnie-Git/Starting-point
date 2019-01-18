/*************************************************************************
	> File Name: ysdzfbmm.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月27日 星期一 13时21分33秒
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	long long int a[1005];
	while (cin >> n >> m) {
		a[0] = 1;
		long long int s = 0;
		for (int i = 1; i <= n; ++i) {
			if (i % 2) {
				a[i] = a[i - 1] * m;
			} else {
				a[i] = a[i - 1] * m - a[i / 2];
			}
			s += a[i];
		}
		cout << s % ((long long int)pow(2, 32))<< endl;
	}
	return 0;
} 

