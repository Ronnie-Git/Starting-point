#include <iostream>
using namespace std;
#define min(a, b) ((a) > (b) ? (b) : (a))

int arr[10], coin[5] = {1, 5, 10, 50, 100};

int solve(int p) {
	int ret = 0;
	for (int i = 4; i >= 0; i--) {
		if (coin[i] > p || arr[i] == 0) continue;
		int cnt = min(p / coin[i], arr[i]);
		p -= coin[i] * cnt;
		ret += cnt;
	}
	if (p) ret = -1;
	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int num = 0, sum = 0, p;
		cin >> p;
		for (int i = 0; i < 5; i++) {
			cin >> arr[i];
			num += arr[i];
			sum += arr[i] * coin[i];
		}
		
		int ans = solve(p);
		if (ans == -1) {
			cout << "-1 -1" << endl;
		} else {
			cout << ans << " " << num - solve(sum - p) << endl;
		}
	}
	return 0;
}
