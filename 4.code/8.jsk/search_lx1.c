/*************************************************************************
	> File Name: search_lx1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月12日 星期一 17时23分24秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRHash(char *str) {
    int seed = 32, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

int main() {
    int n;
    char str[150];
    scanf("%d", &n);
    HashTable *h = init_hashtable(n + 5);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        for (int i = 0; str[i]; i++) {
            if (str[i] > 90) str[i] -= 32;
        }
        printf("%s\n", search(h, str) ? "Yes" : "No");
        insert(h, str);
    }
    return 0;
}
