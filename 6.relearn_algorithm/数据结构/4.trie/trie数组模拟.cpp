const int maxn =2e6+5;
int tree[maxn][30]; //tree[i][j]��ʾ�ڵ�i�ĵ�j�����ӵĽڵ���
bool flagg[maxn]; //��ʾ�Ըýڵ��β��һ������
int tot; //�ܽڵ���
int sum[maxn];

void insert(char *str) {
	int len = strlen(str);
	int root = 0;
	for (int i = 0; i < len; i++) {
		int id = str[i] - '0';
		if (!tree[root][id]) tree[root][id] = ++tot;
		//sum[tree[root][id]]++; // ��ĳ������Ϊǰ׺���ַ������� 
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
	tot = 0;//RE�п��������������
}
