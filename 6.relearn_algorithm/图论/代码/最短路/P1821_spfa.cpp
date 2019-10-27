#include <iostream>
#include <queue>
#define maxn  1005
#define INF 0x3f3f3f3f
using namespace std;

int graph[maxn][maxn],flag[maxn],dist[maxn];
// 邻接矩阵，判断是否在队列中，最短路
int arr[maxn][maxn], num[maxn];

void init(int n) {
	for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) graph[i][j] = arr[i][j] = 0;
            else graph[i][j] = arr[i][j] = INF;
        }
    }
}

void SPFA(int s, int n) {
    queue<int>q;
    for (int i = 0; i <= n; i++) dist[i] = INF;
    q.push(s);
    dist[s] = 0;
    flag[s] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        flag[temp] = false;
        for (int i = 0; i <= n; i++) {
            if (dist[i] > dist[temp] + graph[temp][i]) {
                dist[i] = dist[temp] + graph[temp][i];
                if (!flag[i]) {
                    q.push(i);
                    flag[i] = true;
                }
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    init(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = arr[y][x] = z;
    }
    SPFA(s, n); 
    for (int i = 0; i <= n; i++) {
    	num[i] = dist[i];
    	for (int j = 0; j <= n; j++) {
    		graph[i][j] = arr[i][j];
		}
	}
	SPFA(s, n);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int w = dist[i] + num[i];
		if (w < INF && w > ans) ans = w;
	}
	cout << ans << endl;
    return 0;
}
