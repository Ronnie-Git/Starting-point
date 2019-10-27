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
    bool operator< (const node &a)const {  // ������е�Ԫ���Զ��������С��������  
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
    priority_queue<node>Q; // �������ȶ���  
    int ans = 0;  
    Q.push(node(s, 0));  // ���������  
    while (!Q.empty()) {   
        node now = Q.top(); Q.pop();  // ȡ��������С�ĵ�  
        int v = now.v;  
        if (vis[v]) continue;  // ͬһ���ڵ㣬���ܻ�����2�λ�2�����϶��У�������һ������Ǻ�ʣ�µ���Ҫֱ�������� 
        vis[v] = 1;  // ���һ��  
        ans += min(now.len, w);
        for (int i = 0; i < G[v].size(); i++) {  // ��ʼ����  
            int v2 = G[v][i].v;  
            int len = G[v][i].len;
            if (!vis[v2] && dis[v2] > len) {   
                dis[v2] = len;  
                Q.push(node(v2, dis[v2]));  // ���µĵ������в����� 
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
