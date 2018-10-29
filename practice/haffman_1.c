/*************************************************************************
	> File Name: haffman.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月28日 星期日 20时01分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node {
    int key, freq; // key->askII freq->频数
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *build_haffman(Node **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // i控制循环次数 决定本轮频数第一小和第二小放置的位置（数组下标）即本轮数组的最后一位和倒数第二位
        for (int j = 0; j < n - i - 2; j++) { // i增加后j的边界缩小（等同于将上一轮中频数第一小的和频数第二小的删除）
            // 找出频数第一小的和第二小的
            if (arr[j]->freq < arr[n - i - 1]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            } 
            if (arr[j]->freq < arr[n - i - 2]->freq){
                swap_node(arr + j, arr + n - i - 2);
            }
        }
        // 频数第一小的和频数第二小的建成一棵树重新放回数组中（将原来频数第一小的和第二小的从数组中删除）
        Node *temp = getNewNode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    // 将树的每个节点中的key赋值为从根节点到达它的路径值（左：0 右：1）
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);
    char code[256][20] = {0}, buff[20] = {0};
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
}
