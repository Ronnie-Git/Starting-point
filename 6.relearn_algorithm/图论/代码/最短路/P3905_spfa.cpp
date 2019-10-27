#include <iostream>
#include <queue>
#define maxn  1000
#define INF 0x3f3f3f3f
using namespace std;

int graph[maxn][maxn], flag[maxn], dist[maxn];
int arr[maxn][maxn] = {0}; 

void SPFA(int s, int n) {
    queue<int>q;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    q.push(s);
    dist[s] = 0;
    flag[s] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        flag[temp] = false;
        for (int i = 1; i <= n; i++) {
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
    int n, m, s, t, x, y, z;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        arr[x][y] = arr[y][x] = z;
        graph[x][y] = graph[y][x] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
    	cin >> x >> y;
    	graph[x][y] = graph[y][x] = arr[x][y];
	}
    cin >> s >> t;
    SPFA(s, n);
    if (dist[t] < INF) cout << dist[t] << endl;
    else cout << "-1" << endl;
    return 0;
}
