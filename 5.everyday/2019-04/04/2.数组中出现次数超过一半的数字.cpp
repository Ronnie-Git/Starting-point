/*************************************************************************
	> File Name: 2.数组中出现次数超过一半的数字.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年04月04日 星期四 18时55分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0) return 0;
        map<int, long long> m;
        int cnt = numbers[0];
        m[numbers[0]] = 1;
        for (long long i = 1; i < numbers.size(); i++) {
            if (m.find(numbers[i]) != m.end()) {
                m[numbers[i]] += 1;
                cout << numbers[i] << " " << m[numbers[i]] << endl;
                if (m[numbers[i]] > m[cnt]) cnt = numbers[i];
            } else {
                m[numbers[i]] = 1;
            }
        }
        if (m[cnt] > numbers.size() / 2) return cnt;
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << s.MoreThanHalfNum_Solution(v) << endl;
    return 0;
}
