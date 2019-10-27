#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn =2e6+5;
int tree[maxn][30]; //tree[i][j]表示节点i的第j个儿子的节点编号
bool flagg[maxn]; //表示以该节点结尾是一个单词
int tot; //总节点数
int sum[maxn];

void insert(char *str) {
	int len = strlen(str);
	int root = 0;
	for (int i = 0; i < len; i++) {
		int id = str[i] - '0';
		if (!tree[root][id]) tree[root][id] = ++tot;
		sum[tree[root][id]]++;
		root = tree[root][id];
	}
	flagg[root] = true;
	return ; 
}

int find(char *str) {
    int len = strlen(str);
    int root = 0;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (!tree[root][id]) return 0;
        root = tree[root][id];
    }
    return sum[root];
}

int main() {
	char str[100] = {0};
	while (gets(str)) {
		if (strlen(str) == 0) break;
		insert(str);
	}
	while (scanf("%s", str) != EOF) {
		cout << find(str) << endl;
	}
	return 0;
}
