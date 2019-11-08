#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 3005
typedef long long LL;
LL a[MAXN], b[MAXN];
LL dp[2][MAXN] = {0};
int n, m;

LL LCIS() {
    LL ans = 0;
    for (int i = 0 ; i < n ; ++i) {
        int max_dp = 0;
        for (int j = 0 ; j < m ; ++j) {
            dp[(i + 1) % 2][j + 1] = dp[i % 2][j + 1];
            if (a[i] > b[j] && max_dp < dp[(i + 1) % 2][j + 1]) max_dp = dp[(i + 1) % 2][j + 1];
            if (a[i] == b[j]) {
                dp[(i + 1) % 2][j + 1] = max_dp + 1;
            }
            ans = max(ans, dp[(i + 1) % 2][j + 1]);
        }
    }
    return ans;
}

int main() {
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	cout << LCIS() << endl;
	return 0;
}
