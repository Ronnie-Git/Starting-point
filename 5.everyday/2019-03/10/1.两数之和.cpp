/*************************************************************************
	> File Name: 1.两数之和.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月10日 星期日 18时36分40秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find(vector<int>& v, int key) {
    int l = 0, r = v.size() - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (v[mid] == key) return mid;
        if (v[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

vector<int> get_two_sum(vector<int>& numbers, int target) {
    vector<int> ans;
    for (int i = 0; i < numbers.size(); i++) {
        int temp = target - numbers[i];
        if (temp == numbers[i]) continue;
        int ind = find(numbers, temp);
        if (ind != -1) {
            ans.push_back(i);
            ans.push_back(ind);
            break;
        }
    }
    return ans;
}
int main() {
	int n;
	vector<int> v;
	cin >> n;
	int tp;
	for (int i = 0; i < n; ++i) {
		cin >> tp;
		v.push_back(tp);
	}
	int x;
	cin >> x;
	vector<int> ans = get_two_sum(v, x);
	if (ans.size() == 2) {
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}
