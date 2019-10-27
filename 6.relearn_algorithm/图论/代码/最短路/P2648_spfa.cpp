/*
* spfa
* 1.求最多可以赚多少钱     =>    权值存其负值：-d 或 z - d
* 2.可以赚无限多的钱       =>    判断负环
* 3.从任意起点开始         =>    将 0 作为起点，0 到其余点的权值为 -d 
*/

#include <iostream>
#include <queue>

using namespace std;

#define maxn 1005
#define INF 0x3f3f3f3f

int g[maxn][maxn], dist[maxn], inq[maxn], cnt[maxn];
int n, m;

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	return ;
}

int spfa(int s) {
	for (int i = 0; i <= n; i++) dist[i] = INF;
	queue<int> q;
	q.push(s), inq[s] = 1;
	dist[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop(), inq[v] = 0;
		if (++cnt[v] > n) return 1;
		for (int i = 0; i <= n; i++) {
			if (dist[i] > dist[v] + g[v][i]) {
				dist[i] = dist[v] + g[v][i];
				if (!inq[i]) {
					q.push(i), inq[i] = 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int tol, f, x, y, z, ans = 0;
	cin >> tol >> m >> n >> f;
	init();
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x][y] = -tol;
	}
	for (int i = 0; i < f; i++) {
		cin >> x >> y >> z;
		g[x][y] = z - tol;
	}
	for (int i = 1; i <= n; i++) {
		g[0][i] = -tol;
	}
	if (spfa(0)) {
		cout << "orz" << endl;
	} else {
		for (int i = 1; i <= n; i++) ans = min(ans, dist[i]);
		cout << -ans << endl;
	}
	return 0;
} 
