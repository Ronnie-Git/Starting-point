#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int digit_t = (t == 10 ? 2 : 1);
	if (t == 10 && n == 1) {
		cout << "-1";
	} else {
		cout << t;
		for (int i = digit_t + 1; i <= n; i++) cout << "0";
	}
	cout << endl;
	return 0;
}
