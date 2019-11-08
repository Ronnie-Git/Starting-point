// 二分前缀和 
#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 100005
#define EPS 1e-5
int arr[MAXN];
int n, m;

int check(double x) {
	double sum[MAXN] = {0};
	double mins = 1e10;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + 1.0 * arr[i] - x;
	for (int i = m; i <= n; i++) {
		mins = min(sum[i - m], mins);
		if (sum[i] > mins) return 1;
	}
	return 0;
}

int search() {
	double l = 0.0, r = MAXN, mid;
	while (r - l > EPS) {
		mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	return int(r * 1000);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	printf("%d\n", search());
	return 0;
}
