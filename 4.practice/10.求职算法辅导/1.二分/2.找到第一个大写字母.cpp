/*************************************************************************
	> File Name: 2.找到第一个大写字母.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年02月24日 星期日 18时45分47秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int find_first_capital_letter(string &str) {
    int len = str.size();
    int l = 0, r = len, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (str[mid] >= 'A' && str[mid] <= 'Z') r = mid;
        else l = mid + 1;
    }
    return (l == len ? -1 : l);
}
int main() {
    string str;
    cin >> str;
    for (int i = 0; i < 100000; ++i) {
        find_first_capital_letter(str);
    }
    cout << find_first_capital_letter(str) << endl;
    return 0;
}
