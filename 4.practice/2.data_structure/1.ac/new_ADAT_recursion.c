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
#define max(a, b) ((a) > (b) ? (a) : (b))
#define has_child(data, temp_ind, temp_i) (abs(data[data[temp_ind].base + temp_i].check) == temp_ind)

typedef struct DANode {
    int base, check, fail;
    char *str;
} DANode;

typedef struct Node {
    int flag;
    char *str;
    struct Node *next[BASE];
} Node, *Trie;

int node_cnt = 0;

Node *get_new_node() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    node_cnt += 1;
    return p;
}

void clear(Trie root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    if (root->flag) free(root->str);
    free(root);
    return ;
}

Node *insert(Trie root, const char *str) {
    if (root == NULL) root = get_new_node();
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[ind] == NULL) p->next[ind] = get_new_node();
        p = p->next[ind];
    }
    p->flag = 1;
    p->str = strdup(str);
    return root;
}

int get_base(Node *node, DANode *data) {
    int base = 2, flag = 0;
    while (!flag) {
        flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            if (data[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        base += (!flag);
    }
    return base;
}

int build(Node *node, DANode *data, int ind) {
    if (node == NULL) return 0;
    if (node->flag) data[ind].check = -data[ind].check, data[ind].str = node->str;
    int max_ind = ind;
    data[ind].base = get_base(node, data);
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        data[data[ind].base + i].check = ind;
    }
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        int temp = build(node->next[i], data, data[ind].base + i);
        max_ind = max(max_ind, temp);
    }
    return max_ind;
}

void build_ac(DANode *trie, int ind) {
    if (ind == 0) return ;
    if (trie[ind].fail == 0) build_ac(trie, abs(trie[ind].check));
    for (int i = 0; i < BASE; i++) {
        if (!has_child(trie, ind, i)) continue;
        if (trie[trie[ind].base + i].fail) continue;
        int p = trie[ind].fail;
        while (p && !has_child(trie, p, i)) {
            if (trie[p].fail == 0) build_ac(trie, abs(trie[p].check));
            p = trie[p].fail;
        }
        if (p == 0) p = 1;
        else p = trie[p].base + i;
        trie[trie[ind].base + i].fail = p;
        build_ac(trie, trie[ind].base + i);
    }
    return ;
}

void search_ac(DANode *data, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        while (p && !has_child(data, p, str[i] - BEGIN_LETTER)) p = data[p].fail;
        if (p == 0) p = 1;
        else p = data[p].base + str[i] - BEGIN_LETTER;
        int q = p;
        while (q) {
            if (data[q].check < 0) printf("find string : %s\n", data[q].str);
            q = data[q].fail;
        }
    }
    return ;  
}


void output_da(DANode *data, int n) {
    for (int i = 1; i <= n; i++) {
        if (i - 1 && i % 5 == 1) printf("\n");
        printf("(%2d %2d %3d)    ", i, data[i].base, data[i].check);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    Trie root = NULL;
    char str[100005] = {0};
    scanf("%s", str);
    root = insert(root, str);
    #define INSERT_CNT 100
    DANode *data = (DANode *)calloc(sizeof(DANode), (INSERT_CNT * 100));
    int da_cnt = build(root, data, 1);
    data[0].fail = 0;
    data[1].fail = 0;
    build_ac(data, 1);

    //output_da(data, da_cnt);
    
    scanf("%s", str);
    search_ac(data, str);
    #undef INSERT_CNT 
    return 0;
}

