#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define maxn 1005

struct qnode{
	int v;
	double dis;
	qnode(int v = 0, double dis = 0) : v(v), dis(dis) {} //起点，最短值
	bool operator< (const qnode &r) const {
		return dis > r.dis;
	}
};
struct Edge{
	int v;
	double w;
	Edge(int v = 0, double w = 0) : v(v), w(w) {} //邻接点，权值
};
vector<Edge> ve[maxn];
double d[maxn];
bool vis[maxn];
int n, m;

void addEdge(int u, int v, double w) {
	ve[u].push_back(Edge(v,w));
}

void dijkstra(int s) {
	for (int i = 0; i <= n; i++) d[i] = INF;
	priority_queue<qnode> q;
	q.push(qnode(s, 0));
	d[s] = 0;
	while(!q.empty()) {
		qnode tmp = q.top();
		q.pop();
		int u = tmp.v;
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = 0; i < ve[u].size(); i++) {
			int v = ve[u][i].v;
			double w = ve[u][i].w;
			if (!vis[v] && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(qnode(v, d[v]));
			}
		}
	}
	return ;
}

int x[maxn], y[maxn]; 

int main() {
	int a, b, s, t;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		double w = sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
		addEdge(a, b, w);
		addEdge(b, a, w);
	}
	cin >> s >> t;
	dijkstra(s);
	printf("%.2lf\n", d[t]);
	return 0;
}
