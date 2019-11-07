#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 1000005
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef long long LL;

struct Node {
	LL h, v;
} arr[MAXN];
LL num[MAXN] = {0};
int q[MAXN] = {0}, cnt = -1;

void func(int i) {
	while (cnt > -1 && arr[i].h > arr[q[cnt]].h) num[i] += arr[q[cnt--]].v;
	if (cnt > -1) num[q[cnt]] += arr[i].v;
	q[++cnt] = i;
	return ;
}

int main() {
	int n;
	LL ans = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].h, &arr[i].v);
		func(i);
	}
	for (int i = 0; i < n; i++) ans = max(ans, num[i]);
	
	printf("%lld\n", ans);
	return 0;
}
