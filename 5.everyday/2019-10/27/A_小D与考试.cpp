#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

map<string, string> p;

int main() {
	int n, m;
	string text, ans;
	char ch;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> text >> ans;
		p[text] = ans;
	}
	for (int i = 0; i < m; i++) {
		cin >> text;
		string temp = p[text];
		for (char j = 'A'; j <= 'D'; j++) {
			cin >> ans;
			if (temp == ans) ch = j;
		}
		printf("%c\n", ch);
	}
	return 0;
} 
