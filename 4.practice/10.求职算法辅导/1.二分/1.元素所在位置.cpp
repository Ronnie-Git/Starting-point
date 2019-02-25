/*************************************************************************
	> File Name: 1.元素所在位置.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月24日 星期日 18时28分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
int binary_search(int target, int *num, int len) {
	int l = 0, r = len - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (num[mid] == target) return mid;
        if (num[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main() {
	int num[1000000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		cout << binary_search(value, num, n) << endl;
	}
	return 0;
}
