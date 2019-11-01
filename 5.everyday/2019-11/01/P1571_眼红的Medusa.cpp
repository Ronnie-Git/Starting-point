#include <iostream> 
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAXN 100005

int num[MAXN], arr[MAXN];

int binary_search(int l, int r, int target) {
	if (l > r || target < arr[l] || target > arr[r]) return -1;
	
	int mid = (l + r) >> 1;
	if (arr[mid] == target) return mid;
	if (arr[mid] > target) return binary_search(l, mid - 1, target);
	else return binary_search(mid + 1, r, target);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < m; i++) cin >> arr[i];
	sort(arr, arr + m);
	for (int i = 0; i < n; i++) {
		if (binary_search(0, m - 1, num[i]) != -1) cout << num[i] << " ";
	}
	return 0;
}
