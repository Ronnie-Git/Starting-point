#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 50005;

struct node {  
    int v, len;
    node(int v = 0, int len = 0) :v(v), len(len) {}  
    bool operator< (const node &a)const {  // 加入队列的元素自动按距离从小到大排序  
        return len > a.len;  
    }  
};

vector<node> G[maxn];
int vis[maxn];
int dis[maxn];

void init() {  
    for (int i = 0; i < maxn; i++) {  
        G[i].clear();
        dis[i] = INF;  
        vis[i] = 0;  
    }  
}

void insert(int a, int b, int w) {
	G[a].push_back(node(b, w));
	G[b].push_back(node(a, w));
}

int prim(int s, int w) {  
    priority_queue<node>Q; // 定义优先队列  
    int ans = 0;  
    Q.push(node(s, 0));  // 起点加入队列  
    while (!Q.empty()) {   
        node now = Q.top(); Q.pop();  // 取出距离最小的点  
        int v = now.v;  
        if (vis[v]) continue;  // 同一个节点，可能会推入2次或2次以上队列，这样第一个被标记后，剩下的需要直接跳过。 
        vis[v] = 1;  // 标记一下  
        ans += min(now.len, w);
        for (int i = 0; i < G[v].size(); i++) {  // 开始更新  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;
            if (!vis[v2] && dis[v2] > len) {   
                dis[v2] = len;  
                Q.push(node(v2, dis[v2]));  // 更新的点加入队列并排序 
            }  
        }  
    }  
    return ans; 
} 

int main() {
	int n, w, c;
	cin >> w >> n;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (i == j) continue;
			if (c == 0) c = w;
			insert(i, j, c);
		}
	}
	cout << prim(1, w) + w << endl;
	return 0;
}
