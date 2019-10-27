#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 505; // 点
const int MAXM = 300005; // 边

int n, m;
int fa[MAXN];
typedef struct Edge {
    int a, b, dist; // 两端点、边权 
} Edge;
Edge edges[MAXM];


bool cmp(Edge x, Edge y) { return x.dist < y.dist; }
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int kruskal(int w) {
    int ans = w;
    for (int i = 0; i < n; ++i) fa[i] = i;
    sort(edges, edges + m, cmp); // 根据边权排序 
    for (int i = 0; i < m; ++i) {
        Edge e = edges[i];
        int x = find(e.a), y = find(e.b);
        if (x != y) {
			ans += min(e.dist, w);
			fa[x] = y; // 合并 
		}
    }
    return ans;
}

int main() {
	int w, cnt = 0, c;
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 0) c = w;
			if (i == j) continue;
			edges[cnt].a = i, edges[cnt].b = j;
			edges[cnt].dist = c;
			cnt += 1;
		}
	}
	m = cnt;
	cout << kruskal(w) << endl;
	return 0;
} 
