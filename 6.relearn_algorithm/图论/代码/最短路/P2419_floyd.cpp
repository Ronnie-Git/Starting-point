#include <iostream>

using namespace std;

#define maxn 1005
#define INF 0x3f3f3f3f

int g[maxn][maxn];

void floyd(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = (g[i][j] || g[i][k] && g[k][j]);
			}
		}
	}
	return ;
}

int main() {
	int n, m, x, y, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x][y] = 1;
	}
	floyd(n);
	for (int i = 1; i <= n; i++) {
		int flag = 1;
		for (int j = 1; j <= n; j++) { // 能确定排名的一定能和其余点连通 
			if (i == j) continue;
			flag = flag && (g[i][j] || g[j][i]);
		}
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}
