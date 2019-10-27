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
		//sum[tree[root][id]]++; // 以某串单词为前缀的字符串数量 
		root = tree[root][id];
	}
	flagg[root] = true;
	return ; 
}

bool find(char *str) {
    int len = strlen(str);
    int root = 0;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (!tree[root][id]) return false;
        root = tree[root][id];
    }
    return true;
}

void clear() {
	for (int i = 0; i <= tot; i++) {
		flagg[i] = false;
		for (int j = 0; j < 10; j++)
			tree[i][j] = 0;
    }
	tot = 0;//RE有可能是这里的问题
}
