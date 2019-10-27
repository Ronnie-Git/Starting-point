#include <iostream>
#include <queue> 
#include <cstring>

using namespace std;

#define maxn 500010

struct Aho_Corasick_Automaton {
    int c[maxn][26], val[maxn], fail[maxn], cnt;
    queue<int> q;
    void insert(char *s) {
        int len = strlen(s), now = 0;
        for (int i = 0; i < len; i++) {
            int v = s[i] - 'a';
            if (!c[now][v]) c[now][v] = ++cnt;
            now = c[now][v];
        }
        val[now]++;
    }
    void build() {
        for (int i = 0; i < 26; i++) {
			if (c[0][i]) fail[c[0][i]] = 0, q.push(c[0][i]);
		}
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
            	if (c[u][i]) fail[c[u][i]] = c[fail[u]][i], q.push(c[u][i]);
            	else c[u][i] = c[fail[u]][i];
            }
        }
    }
    int query(char *s) {
        int len = strlen(s); int now = 0, ans = 0;
        for (int i = 0; i < len; i++) {
            now = c[now][s[i]-'a'];
            for (int t = now; t && ~val[t]; t = fail[t]) {
				ans += val[t], val[t] = -1;
			}
        }
        return ans;
    }
} AC;

char str[1000005];
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> str;
		AC.insert(str);
	}
	AC.build();
	cin >> str;
	int ans = AC.query(str);
	cout << ans << endl;
    return 0;
}
