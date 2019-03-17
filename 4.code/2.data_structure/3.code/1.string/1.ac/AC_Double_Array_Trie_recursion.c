/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月20日 星期日 16时09分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASE 26
#define BEGIN_LETTER 'a'
#define has_child(data, temp_ind, temp_i) (abs(data[data[temp_ind].base + temp_i].check) == temp_ind)

typedef struct DANode {
    int base, check, fail;
    char *str;
} DANode;

typedef struct Node {
    int flag;
    char *str;
    struct Node *next[BASE];
} Node;

Node *get_new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    if (root->flag) free(root->str);
    free(root);
    return ;
}

int insert(Node *root, const char *str) {
    int cnt = 0;
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = get_new_node(), ++cnt;
        p = p->next[ind];
    }
    p->flag = 1;
    p->str = strdup(str);
    return cnt;
}

int get_base(Node *node, DANode *trie) {
    int base = 2, flag = 0;
    while (!flag) {
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        base += (!flag);
    }
    return base;
}

void build_DAT(Node *node, DANode *trie, int ind) {
    if (node == NULL) return ;
    if (node->flag) trie[ind].check = -trie[ind].check, trie[ind].str = node->str;
    trie[ind].base = get_base(node, trie);
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        build_DAT(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

void build_ac(DANode *trie, int ind) {
    // 下标为0的位置不使用 如果传过来的下标为0证明该节点不存在
    if (ind == 0) return ; 

    // 当前节点没建立失败指针 递归它的父亲节点从而建立它的失败指针
    if (trie[ind].fail == 0) build_ac(trie, abs(trie[ind].check)); 

    for (int i = 0; i < BASE; i++) {
        if (!has_child(trie, ind, i)) continue;
        if (trie[trie[ind].base + i].fail) continue;  // 防止重复建立失败指针
        
        // 确立孩子节点的失败指针
        int p = trie[ind].fail;
        while (p && !has_child(trie, p, i)) {
            if (trie[p].fail == 0) build_ac(trie, abs(trie[p].check));
            p = trie[p].fail;
        }
        if (p == 0) p = 1; // 根节点下标为1
        else p = trie[p].base + i;
        trie[trie[ind].base + i].fail = p;
        
        build_ac(trie, trie[ind].base + i);
    }
    return ;
}

void search_ac(DANode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        while (p && !has_child(trie, p, str[i] - BEGIN_LETTER)) p = trie[p].fail;
        if (p == 0) p = 1;
        else p = trie[p].base + str[i] - BEGIN_LETTER;
        int q = p;
        while (q) {
            if (trie[q].check < 0) printf("find string : %s\n", trie[q].str);
            q = trie[q].fail;
        }
    }
    return ;  
}

int main() {
    int n, cnt = 0;
    Node *root = get_new_node();
    char str[100005] = {0};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        cnt += insert(root, str);
    }

    DANode *trie = (DANode *)calloc(sizeof(DANode), (cnt * 2));
    build_DAT(root, trie, 1);
    build_ac(trie, 1);
    
    scanf("%s", str);
    search_ac(trie, str);
    return 0;
}

