/*************************************************************************
	> File Name: BST.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月17日 星期一 09时47分00秒
 ************************************************************************/

#ifndef _BST_H
#define _BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Tree;

TreeNode *getTreeNode(int value) {
    TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
    T->data = value;
    T->left = T->right = NULL;
    return T; 
}

int SearchTree(Tree T, int value, int len) {
    if (T == NULL) return -1;

    if (value < T->data)
        return SearchTree(T->left, value, len + 1);
    else if (value > T->data)
        return SearchTree(T->right, value, len + 1);
    else 
        return len;
}

TreeNode *InsertTree(Tree T, int value) {
    if (T == NULL) 
        T = getTreeNode(value);
    else if (value < T->data) 
        T->left = InsertTree(T->left, value);
    else 
        T->right = InsertTree(T->right, value);
    
    return T;
}

void outputTree(Tree T) {
    if (!T) return ;
    printf("%d ", T->data);
    outputTree(T->left);
    outputTree(T->right);
    return ;
}

void ClearTree(Tree T) {
    if (T != NULL) {
        ClearTree(T->left);
        ClearTree(T->right);
        free(T);
    }

    return ;
}
#endif
