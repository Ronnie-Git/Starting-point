/*************************************************************************
	> File Name: trie_jsk_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月05日 星期六 16时59分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100010;
const int SIZE = 26;
const char BASE = 'a';

typedef struct TrieNode {
    int is_terminal;
    struct TrieNode** childs;
} TrieNode, *Trie;

TrieNode* new_node() {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->is_terminal = 0;
    return p;
}

void clear(TrieNode *p) {
    if (p != NULL) {
        for (int i = 0; i < SIZE; i++) {
            if (p->childs[i] != NULL) {
                clear(p->childs[i]);
            }
        }
        free(p->childs);
        free(p);
    }
}

void insert(Trie trie, char *pattern, int *ans) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(pattern); i++) {
        if (p->childs[pattern[i] - BASE] == NULL) {
            p->childs[pattern[i] - BASE] = new_node();
        }
        p = p->childs[pattern[i] - BASE];
        if (p->is_terminal) continue;            
        p->is_terminal = 1;
        *ans += 1;
    }
}

int main() {
    Trie root = new_node();
    char str[100010] = {0};
    char temp[100010] = {0};
    scanf("%s", str);
    int ans = 0;
    for (int i = 0; str[i]; i++) {
        memset(temp, 0, sizeof(temp));
        strncpy(temp, str + i, strlen(str + i));
        insert(root, temp, &ans);
    }
    printf("%d\n", ans);
    clear(root);
    return 0;
}
