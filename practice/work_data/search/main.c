/*************************************************************************
	> File Name: main.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月16日 星期日 20时34分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"
#include "search.h"
#include "BST.h"

int main() {
    int n, len = 0;
    srand(time(0));
    scanf("%d", &n);

    int *num = (int *)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n; i++) {
        num[i] = rand() % (2 * n) + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    len = search(num, n, n / 2);
    if (len != -1) {
        printf("search() 成功找到, 长度为 %d\n", len);
    } else {
        printf("search() 没找到\n");
    }

    HashTable *h = init_hashtable(n);
    for (int i = 0; i < n; i++) {
        insert_hashtable(h, num[i]);
    }
    len = search_hashtable(h, n / 2);
    if (len != -1) {
        printf("search_hashtable() 成功找到, 长度为 %d\n", len);
    } else {
        printf("search_hashtable() 没找到\n");
    }

    Tree t = NULL;
    for (int i = 0; i < n; i++) {
        t = InsertTree(t, num[i]); 
    }
    len = SearchTree(t, n / 2, 1);
    if (len != -1) {
        printf("SearchTree() 成功找到, 长度为 %d\n", len);
    } else {
        printf("SearchTree() 没找到\n");
    }
    
    clear_arr(num);
    clear_hashtable(h);
    ClearTree(t);
    return 0;
}
