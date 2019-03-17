/*************************************************************************
	> File Name: p1308.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月23日 星期四 15时14分34秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	b = ' ' + b + ' '; 
	for (int i = 0; i < a.length(); ++i) a[i] = tolower(a[i]);
	for (int i = 0; i < b.length(); ++i) b[i] = tolower(b[i]);
	int i = 0, j = 0, l = 0, f = 0, t = 0;
	while (i < b.length()) {
		if (!l) t = i - 1;
		if (b[i] != a[j]) {
			i++;
			j = 0;
		} else {
			while (b[i] == a[j]) {
				j++;
				i++;
			}
			if (j == a.length() && b[i - a.length() - 1] == ' ' && b[i] == ' ') l++;
		}
	}
	if (l) {
		cout << l << " " << t;
	} else {
		cout << "-1";
	}
	return 0;
}
