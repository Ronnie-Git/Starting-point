#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 5005; // ��
const int MAXM = 200005; // ��

int n, m;
int fa[MAXN];
typedef struct Edge {
    int a, b, dist; // ���˵㡢��Ȩ 
} Edge;
Edge edges[MAXM];


bool cmp(Edge x, Edge y) { return x.dist < y.dist; }
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int kruskal() {
    int ans = 0;
    for (int i = 0; i <= n; ++i) fa[i] = i;
    sort(edges, edges + m, cmp); // ���ݱ�Ȩ���� 
    for (int i = 0; i < m; ++i) {
        Edge e = edges[i];
        int x = find(e.a), y = find(e.b);
        if (x != y) {
			ans += e.dist;
			fa[x] = y; // �ϲ� 
		}
    }
    return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].dist;
	}
	cout << kruskal() << endl;
	return 0;
} 
