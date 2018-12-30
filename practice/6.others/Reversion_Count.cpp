/*************************************************************************
	> File Name: Reversion_Count.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月05日 星期三 17时11分06秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
char b[105];
int x[105], y[105], z[105], n, i, h, g;
int q(int l) {
	if (z[l - 1] > 0) {
		z[l - 1] -= 1;
		z[g] = 10 + x[g] - y[g]; 
	} else {
		z[l - 1] = 9;
		q(l - 1);
	}
}
int p(int l) {
	if (z[l - 1] > 0) {
		z[l - 1] -= 1;
		z[g] = 10 + y[g] - x[g]; 
	} else {
		z[l - 1] = 9;
		p(l - 1);
	}
}
int main() {
	while (cin >> b) {
		i = strlen(b);
		for (int j = 0; j < i; ++j) {
			x[j] = b[j] - '0';
		}
		h = i - 1;
		for (int j = 0; j < i; ++j, --h) {
			y[j] = x[h];
		}
		if (x[0] > y[0]) {
			for (int j = 0; j < i; ++j) {
				if (x[j] >= y[j]) {
					z[j] = x[j] - y[j];
				} else {
					g = j;
					q(g);
				}
			}
		} else {
			for (int j = 0; j < i; ++j) {
				if (y[j] >= x[j]) {
					z[j] = y[j] - x[j];
				} else {
					g = j;
					p(g);
				}
			}
		}
		int k = 0, f1 = 1, f2 = 1, f3 = 1;
		while (z[k] == 0 && k < i - 1) k++;
		for (int j = k; j < i; ++j) {
			if (z[j] != 0) f1 = 0;
			if (z[j] != 9) f2 = 0;
			if (j > 0 && j < i - 1 && z[j] != 9) f3 = 0;
		}
		if (z[k] + z[i - 1] == 9 && f3) {
			cout << "YES" << endl;
		} else if (f1) {
			cout << "YES" << endl;
		} else if (f2) { 
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
