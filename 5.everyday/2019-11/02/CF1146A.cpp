#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char arr[100] = {0};
	cin >> arr;
	int len = strlen(arr), cnt = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == 'a') ++cnt;
	}
	int ans = (cnt > len - cnt ? len : cnt + cnt - 1);
	cout << ans << endl;
	return 0;
}
