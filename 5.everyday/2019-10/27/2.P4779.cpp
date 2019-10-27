/*************************************************************************
	> File Name: 2.P4779.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月27日 星期日 19时37分24秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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
    int n, m, s, u, v, w;
    scanf("%d %d %d", &n, &m, &s);
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (dist[i] < inf) printf("%d ", dist[i]);
        else printf("2147483647 ");
    }
    printf("\n");
    return 0;
}

