#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define inf 0x3f3f3f3f
#define maxn 1000005

int dist[maxn], head[maxn], vis[maxn];
struct Edge{
    int next,to,w;
}e[maxn];
typedef pair<int, int> P;
int cnt = 1;
inline void add(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    memset(dist, inf, sizeof(dist));
    
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int u = p.second;
        if (dist[u] < p.first) continue;
        for (int i = head[u]; i; i = e[i].next) {
            int w = e[i].w, v = e[i].to;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                que.push(P(dist[v], v));
            }
        }
    }
    return ;
}
int main(){
    int n, x, y, val;
    scanf("%d %d %d", &n, &x, &y);
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		scanf("%d", &val);
        	if (val) add(i + 1, j + 1, 1);
		}
    }
    dijkstra(x);
    cout << dist[y] - 1 << endl;
    return 0;
}
