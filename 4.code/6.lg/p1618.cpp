/*************************************************************************
	> File Name: p1618.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月03日 星期三 20时46分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int b[5], a, f = 0, c[15], t = 0, n[5];
	cin >> b[0] >> b[1] >> b[2];
	for (int i = 100; i <= 1000; ++i) {
		memset(c, 0, sizeof(c));
		n[0] = i * b[1] / b[0], n[1] = i * b[2] / b[0];
		if (n[0] < 1000 && n[1] < 1000) {
			c[i % 10]++, c[n[0] % 10]++, c[n[1] % 10]++, c[i / 100]++, c[n[0] / 100]++, c[n[1] / 100]++, c[i % 100 / 10]++, c[n[0] % 100 / 10]++, c[n[1] % 100 / 10]++;
			for (int j = 1; j < 10; ++j) {
				if (!c[j]) {
					t = 1;
					break;
				}
			}
			if (!t) {
				cout << i << " " << n[0] << " " << n[1] << endl;
				f = 1;
			}
			t = 0;
		}
	}
	if (!f) cout << "No!!!";
	return 0;
}
