### trie数组模拟

```c++
//对于字符串比较多的要统计个数的，map被卡的情况下，直接用字典树
//很多题都是要用到节点下标来表示某个字符串
const int maxn =2e6+5; //如果是64MB可以开到2e6+5，尽量开大
int tree[maxn][30]; //tree[i][j]表示节点i的第j个儿子的节点编号
bool flagg[maxn]; //表示以该节点结尾是一个单词
int tot; //总节点数

void insert(char *str) {
	int len = strlen(str);
	int root = 0;
	for (int i = 0; i < len; i++) {
		int id = str[i] - '0';
		if (!tree[root][id]) tree[root][id] = ++tot;
		root = tree[root][id];
	}
	flagg[root] = true;
	return ; 
}

bool find(char *str) { //查询操作，按具体要求改动
    int len = strlen(str);
    int root = 0;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (!tree[root][id]) return false;
        root = tree[root][id];
    }
    return true;
}

void clear() { //最后清空，节省时间
	for (int i = 0; i <= tot; i++) {
		flagg[i] = false;
		for (int j = 0; j < 10; j++)
			tree[i][j] = 0;
    }
	tot = 0;//RE有可能是这里的问题
}
```

