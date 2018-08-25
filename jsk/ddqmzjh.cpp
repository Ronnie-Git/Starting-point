/*************************************************************************
	> File Name: ddqmzjh.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月25日 星期六 16时37分15秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, f;
int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
int vis[105][105] = {0};
char map[105][105] = {0};

struct node {
	int x, y;
}b, end;

queue <node> q;

void bfs() {
	while (!q.empty()) {
		node now;
		now = q.front();
		q.pop();
		if (map[now.x][now.y] == 'e') {
			if (vis[now.x][now.y] == 0) break;
			cout << vis[now.x][now.y] << endl;
			f = 1;
			break;
		}
		node next;
		for (int i = 0; i < 8; ++i) {
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			if (map[next.x][next.y] == '#') continue; 
			if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && map[now.x + dir[i][0] / 2][now.y + dir[i][1] / 2] != '#' && !vis[next.x][next.y]) {
				q.push(next);
				vis[next.x][next.y] = vis[now.x][now.y] + 1;
			}
		}
	}
	if (!f) {
		cout << "-1" << endl;
	}
}
int main() {
	while (cin >> n >> m) {
		while(!q.empty()) {
			q.pop();
		}
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 's') {
					b.x = i;
					b.y = j;
				} 
			}
		}
		q.push(b);
		f = 0;
		bfs();
	}
	return 0;
}
