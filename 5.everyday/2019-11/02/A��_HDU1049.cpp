#include <iostream>
using namespace std;

int main() {
	int n, u, d;
	while (cin >> n >> u >> d) {
		if (n == 0 && u == 0 && d == 0) break;
		int ans = 0;
		while (n > 0) {
			if (++ans & 1) n -= u;
			else n += d;
		}
		cout << ans << endl;
	}
	return 0;
}
