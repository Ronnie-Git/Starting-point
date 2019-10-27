#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000005
int arr[maxn];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	long long sum = 0;
	double ans = 0.0, temp;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
		temp = (1.0 * sum * sum) / (1.0 * i);
		if (temp > ans) {
			ans = temp;
		} else {
			break;
		}
	}
	printf("%.9lf\n", ans);
	return 0;
}
