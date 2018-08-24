/*************************************************************************
	> File Name: bhhwt.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月24日 星期五 15时58分00秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int map[10][10] = {0};
int vis[10];
int ans, sum;
bool f(int r, int c) {  
    for (int i = 0; i < r; i++) {  
        if (vis[i] == c) return false;  
        if (abs(r - i) == abs(c - vis[i])) return false;  
    }  
    return true;  
}  
void dfs(int l) {
	if (l == 8) {
		ans = max(ans, sum);
		return ;
	}
	for(int i = 0; i < 8; ++i) {
		if (f(l, i)){
			sum += map[l][i];
			vis[l] = i;
			dfs(l + 1);
			vis[l] = -1;
			sum -= map[l][i];
		}
	}
}
int main() {
	int k;
	cin >> k;
	while (k--) {
		memset(map, 0, sizeof(map));
		memset(vis, -1, sizeof(vis));
		ans = 0, sum = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				cin >> map[i][j];
			}
		} 
		dfs(0);
		cout << ans << endl;
	}
	return 0;
} 
