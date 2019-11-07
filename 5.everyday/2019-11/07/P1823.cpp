#include <iostream>
using namespace std;
#define MAXN 500005

long long arr[MAXN], sum = 0;
int q[MAXN], num[MAXN], cnt = -1;

void func(int i) {
	while (cnt > -1 && arr[i] >= arr[q[cnt]]) {
		sum += num[q[cnt]];
		if (arr[q[cnt]] == arr[i]) num[i] += num[q[cnt]];
		cnt -= 1;
	}
	if (cnt > -1) ++sum;
	q[++cnt] = i;
	return ;
}

int main() {
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		num[i] = 1;
		func(i);
	}
	cout << sum << endl;
	return 0;
}
