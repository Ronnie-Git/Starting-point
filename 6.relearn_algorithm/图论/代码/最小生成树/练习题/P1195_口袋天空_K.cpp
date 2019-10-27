/*
* Kruskal �㷨
* n������� n ������kruskalÿ�κϲ��Ķ�����С���ѣ��� n �����ϲ��� k ����Ϊֹ 
*/
#include <iostream>
#include <algorithm>

using namespace std;


const int MAXN = 1005; // ��
const int MAXM = 10005; // ��

int n, m, k, cnt;
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
    	if (cnt <= k) break;
        Edge e = edges[i];
        int x = find(e.a), y = find(e.b);
        if (x != y) {
			ans += e.dist;
			fa[x] = y; // �ϲ� 	
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
