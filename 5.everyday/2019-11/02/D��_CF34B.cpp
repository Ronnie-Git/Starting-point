#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 105

int main() {
	int arr[MAXN] = {0};
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] <= arr[j + 1]) continue;
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			++cnt;
		}
		if (!cnt) break;
	}
	
	for (int i = 0; i < m; i++) {
		if (arr[i] >= 0) break;
		ans += arr[i];
	}
	cout << -ans << endl;
	return 0;
}
