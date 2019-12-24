#include <iostream>
#include <cmath>
using namespace std;

#define MAXN 500

void mul(int *arr, int *ans) {
	int temp[1005] = {0};
	for (int i = 1; i <= arr[0]; i++) {
		int x = 0;
		for (int j = 1; j <= ans[0]; j++) {
			temp[i + j - 1] += arr[i] * ans[j] + x;
			x = temp[i + j - 1] / 10;
			temp[i + j - 1] %= 10;
		}
		temp[i + ans[0]] = x;
	}
	int len = arr[0] + ans[0];
	while (temp[len] == 0 && len > 1) len--;
	if (len >= MAXN) len = MAXN;
	ans[0] = len;
	for (int i = 1; i <= len; i++) ans[i] = temp[i];
	return ;
}

void quick_pow(int p, int *arr, int *ans) {
	while (p) {
		if (p & 1) mul(arr, ans);
		mul(arr, arr);
		p >>= 1;
	}
	return ;
}

void output(int p, int *ans) {
	cout << floor(p * 1.0 / log2(10.0)) + 1 << endl;
	for (int i = MAXN; i > 0; i--) {
		cout << ans[i];
		if ((i - 1) % 50 == 0) cout << endl;
	}
	return ;
}

int main() {
	int p;
	int arr[MAXN + 5] = {0};
	int ans[MAXN + 5] = {0};
	cin >> p;
	arr[0] = 1, arr[1] = 2;
	ans[0] = 1, ans[1] = 1;
	quick_pow(p, arr, ans);
	ans[1] -= 1;
	output(p, ans);
	return 0;
}