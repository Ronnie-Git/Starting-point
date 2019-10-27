#include <iostream>
#include <cstring>
using namespace std;

#define maxn 105
#define INF 0x3f3f3f3f
char str[maxn] = {0};
int dp[maxn] = {0}, n, m;

int main() {
	cin >> n >> m;
	cin >> str;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] != '1') continue;
		for (int j = 1; j <= m && i + j < n; j++) {
			if (str[i + j] == '1') dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << (dp[n - 1] == INF ? -1 : dp[n - 1]);
	return 0;
}
