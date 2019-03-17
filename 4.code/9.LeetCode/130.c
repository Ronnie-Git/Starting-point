/*************************************************************************
	> File Name: 130.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月21日 星期一 10时03分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->fa = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->fa[x] != x) 
        return (u->fa[x] = find(u, u->fa[x]));
    return x;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->fa[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}

// 获取每个位置编号
int getInd(int i, int j, int m) {
    return i * m + j + 1;
}

// 并查集问题 只需确定矩阵中 O(字母) 与 边界的连通性即可
// 将矩阵中每个位置编号 0号为边界
// 只需将矩阵中每个 O(字母) 与它左或上为 O(字母) 的位置相连即可 边界上的 O(字母) 与0号相连
void solve(char** board, int boardRowSize, int boardColSize) {
    UnionSet *u = init(boardRowSize * boardColSize + 5);
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != 'O') continue;
            if ((i == 0 || i == boardRowSize - 1 || j == 0 || j == boardColSize - 1)) {
                merge(u, 0, getInd(i, j, boardColSize));
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                merge(u, getInd(i, j, boardColSize), getInd(i - 1, j, boardColSize));
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                merge(u, getInd(i, j, boardColSize), getInd(i, j - 1, boardColSize));
            }

        }
    }
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != 'O') continue;
            if (find(u, getInd(i, j, boardColSize)) != find(u, 0)) {
                board[i][j] = 'X';
            }
        }
    }
    clear(u);
    return ;
}

