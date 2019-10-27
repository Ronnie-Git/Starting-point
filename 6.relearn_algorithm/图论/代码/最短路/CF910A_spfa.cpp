#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 1005;
vector<pair<int, int> >Edge[maxn];

int n, m, dist[maxn];
bool flag[maxn];

void init() {
    for (int i = 0; i < maxn; i++) Edge[i].clear();
    for (int i = 0; i < maxn; i++) flag[i] = false;
    for (int i = 0; i < maxn; i++) dist[i] = INF;
}

void spfa(int s) {
	queue<int>q;
    dist[s] = 0;
    flag[s] = true;
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        flag[now] = false;
        for (int i = 0; i < Edge[now].size(); i++) {
            int v = Edge[now][i].first;
            if (dist[v] > dist[now] + Edge[now][i].second) {
                dist[v] = dist[now] + Edge[now][i].second;
                if (!flag[Edge[now][i].first]) {
                    q.push(Edge[now][i].first);
                    flag[Edge[now][i].first] = true;
                }
            }
        }
    }
}

int main() {
	init();
    int s, cnt = 0;
    int arr[maxn] = {0};
    string str;
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < n; i++) {
    	if (str[i] == '1') arr[i] = (++cnt);
	}
    for (int i = 0; i < n; i++) {
    	if (str[i] != '1') continue;
    	for (int j = 1; j <= m && i + j < n; j++) {
    		if (str[i + j] == '1') {
    			Edge[arr[i]].push_back(make_pair(arr[i + j], 1));
			}
    	}
	}
    spfa(1);
    if (dist[cnt] < INF) cout << dist[cnt] << endl;
    else cout << "-1" << endl;
    return 0;
}
