/*
* Kruskal 算法
* n个点就是 n 棵树，kruskal每次合并的都是最小花费，从 n 棵树合并成 k 棵树为止 
*/
#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 1005; // 点
const int MAXM = 10005; // 边

int n, m, k, cnt;
int fa[MAXN];
typedef struct Edge {
    int a, b, dist; // 两端点、边权 
} Edge;
Edge edges[MAXM];


bool cmp(Edge x, Edge y) { return x.dist < y.dist; }
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int kruskal() {
    int ans = 0;
    for (int i = 0; i <= n; ++i) fa[i] = i;
    sort(edges, edges + m, cmp); // 根据边权排序 
    for (int i = 0; i < m; ++i) {
    	if (cnt <= k) break;
        Edge e = edges[i];
        int x = find(e.a), y = find(e.b);
        if (x != y) {
			ans += e.dist;
			fa[x] = y; // 合并 	
			cnt -= 1;
		}
    }
    return ans;
}

int main() {
	cin >> n >> m >> k;
	cnt = n;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].dist;
	}
	cout << kruskal() << endl;
	return 0;
} 
