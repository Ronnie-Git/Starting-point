/*************************************************************************
	> File Name: 2.HDU_2191.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月31日 星期四 08时11分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_V 100005
void pack(int *dp, int V, int v, int n, int w) {
    if (n == 0 || v == 0) return;
  	if (n == 1) {
    	for (int i = V; i >= v; --i) {
      		dp[i] = max(dp[i], dp[i - v] + w);
		}
    	return;
  	}
  	if (n * v >= V - v + 1) {
    	for (int i = v; i <= V; ++i) {
      		dp[i] = max(dp[i], dp[i - v] + w);
		}
    	return;    
  	}
    
  	int va[MAX_V], vb[MAX_V];
  	for (int j = 0; j < v; ++j) {
    	int pb = 0, pe = -1;
    	int qb = 0, qe = -1;  
    	for (int k = j, i = 0; k <= V; k += v, ++i) {
      		if (pe == pb + n) {
        		if (va[pb] == vb[qb]) ++qb; 
        		++pb;
      		}
      		int tt = dp[k] - i * w;
      		va[++pe] = tt;
      		while (qe >= qb && vb[qe] < tt) --qe;
      		vb[++qe] = tt;        
      		dp[k] = vb[qb] + i * w;
    	}
  	}
    return ;
}



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, dp[MAX_V] = {0};
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int c, w, k;
            cin >> c >> w >> k;
            pack(dp, n, c, k, w);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
