#include <iostream>

using namespace std;

#define lowbit(a) ((a) & (-a))
#define maxn 2000010
typedef long long LL;
int n, m;
LL sum1[maxn], sum2[maxn];

void add(LL x, LL k) {
    for(LL i = x; i <= n; i += lowbit(i)) {
        sum1[i] += k, sum2[i] += x * k;
    }
}
void range_add(LL l, LL r, LL x) {
    add(l, x), add(r + 1, -x);
}
LL ask(LL x) {
    LL res = 0;
    for (LL i = x; i; i -= lowbit(i)) {
        res += (x + 1) * sum1[i] - sum2[i];
    }
    return res;
}
LL range_ask(LL l, LL r) {
    return ask(r) - ask(l - 1);
}

int main() {
	int op, x, y, z;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		range_add(i, i, x);
	}
	for (int i = 0; i < m; i++) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> z;
			range_add(x, y, z);
		} else {
			cin >> x >> y;
			cout << range_ask(x, y) << endl;
		}
	}
	return 0;
}
