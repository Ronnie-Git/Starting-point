#include <iostream>


using namespace std;

#define maxn 1000
#define INF 0x3f3f3f3f

int g[maxn][maxn];

void floyd(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp = max(g[i][k], g[k][j]);
				g[i][j] = min(g[i][j], temp);
			}
		}
	}
}

int main() {
	int n, m, k, a, b, val;
	cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> val;
		g[a][b] = val;
	}
	floyd(n);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		if (g[a][b] < INF) cout << g[a][b] << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
