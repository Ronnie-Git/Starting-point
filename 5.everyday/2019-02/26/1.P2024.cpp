/*************************************************************************
	> File Name: 1.P2024.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月26日 星期二 19时15分57秒
 ************************************************************************/

#include <iostream>

using namespace std;

int num[300005] = {0};

int find(int x) {
	if (num[x] == x) return x;
	return num[x] = find(num[x]);
}

int main() {
	int k, n, a, x, y, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= 3 * n; ++i) {
		num[i] = i;
	}
	while (k--) {
		cin >> a >> x >> y;
		if (x > n || y > n) {
			ans++;
		} else if (a == 1) {
			if (find(x + n) == find(y) || find(x) == find(y + n)) {
				ans++;
			} else {
				num[find(x)] = num[find(y)];
				num[find(x + n)] = num[find(y + n)];
				num[find(x + n * 2)] = num[find(y + n * 2)];
			}
		} else {
			if (find(x) == find(y) || find(x) == find(y + n)) {
				ans++;
			} else {
				num[find(x + n)] = num[find(y)];
				num[find(x + n * 2)] = num[find(y + n)];
				num[find(x)] = num[find(y + n * 2)];
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
