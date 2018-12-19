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

int *init_num(int n) {
    int *num = (int *)malloc(sizeof(int) * n + 1);
    for (int i = 0; i < n; i++) {
        num[i] = rand() % (2 * n) + 1;
    }
    return num;
}

int main() {
    int n;
    srand(time(0));
    printf("请输入数据长度：\n");
    scanf("%d", &n);
    
    printf("生成的数据为：\n");
    int *num = init_num(n); // 初始化数据数组
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n\n");
    
    // 初始化哈希
    HashTable *h = init_hashtable(n);
    for (int i = 0; i < n; i++) {
        insert_hashtable(h, num[i]);
    }

    // 初始化BST
    Tree t = NULL;
    for (int i = 0; i < n; i++) {
        t = InsertTree(t, num[i]); 
    }

    printf("请选择使用哪种查找：\n");
    printf("1.顺序查找\n2.哈希查找\n3.二叉排序树查找\n4.以上三种查找，并比较其查找长度\n");
    
    char str[5][100] = {"search()", "search_hashtable()", "SearchTree()"};
    int op, flag = 0, len = -1;

    while (!flag) {
        scanf("%d", &op);
        printf("\n");
        switch(op) {
            case 1: {
                len = search(num, n, n / 2);
                if (len != -1) {
                    printf("%s 成功找到, 查找长度为 %d\n", str[0], len);
                } else {
                    printf("%s 没找到\n", str[0]);
                }
            } break;

            case 2: {
                len = search_hashtable(h, n / 2);
                if (len != -1) {
                    printf("%s 成功找到, 查找长度为 %d\n", str[1], len);
                } else {
                    printf("%s 没找到\n", str[1]);
                }
            } break;

            case 3: {   
                len = SearchTree(t, n / 2, 1);
                if (len != -1) {
                    printf("%s 成功找到, 查找长度为 %d\n", str[2], len);
                } else {
                    printf("%s 没找到\n", str[2]);
                }
            } break;

            case 4: {
                int arr[5] = {0}, ind = 0, min;
                arr[0] = search(num, n, n / 2);
                arr[1] = search_hashtable(h, n / 2);
                arr[2] = SearchTree(t, n / 2, 1);
                if (arr[0] != -1) {
                    printf("%s 成功找到, 查找长度为 %d\n", str[0], arr[0]);
                    printf("%s 成功找到, 查找长度为 %d\n", str[1], arr[1]);
                    printf("%s 成功找到, 查找长度为 %d\n", str[2], arr[2]);
                    printf("\n");
                    for (int i = 0; i < 2; i++) {
                        if (!i) min = arr[i], ind = i;
                        if (min > arr[i]) min = arr[i], ind = i;
                    }
                    printf("%s 查找长度最短\n", str[ind]);
                } else {
                    printf("没找到\n");
                }
            } break;

            default: {
                printf("请输入 1 ~ 4 的数字！\n"); 
                flag = 1;
            } break;
        }
        flag ^= 1;
    }
    
    clear_arr(num);
    clear_hashtable(h);
    ClearTree(t);
    return 0;
}
