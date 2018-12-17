/*************************************************************************
	> File Name: BST.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月17日 星期一 10时01分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

struct TreeNode {
    ElementType Element;
    SearchTree left;
    SearchTree right;
};

Position Find(ElementType X, SearchTree T) {
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->left);
    else if (X > T->Element)
        return Find(X, T->right);
    else 
        return T;
}

Position FindMin(SearchTree T) {
    if (T == NULL)
        return NULL;
    if (T->left == NULL)
        return T;
    else
        return FindMin(T->left);
}

Position FindMax(SearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->right == NULL)
        return T;
    else
        return FindMax(T->right);
}

SearchTree Insert(ElementType X, SearchTree T) {
    if(T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        T->Element = X;
        T->left = T->right = NULL;
    }
    else if (X < T->Element)
        T->left = Insert(X, T->left);
    else if (X > T->Element)
        T->right = Insert(X, T->right);
    return T;
}

SearchTree Delete(ElementType X, SearchTree T) {
    Position TmpCell;
    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        T->left = Delete(X, T->left);
    else if (X > T->Element)
        T->right = Delete(X, T->right);
    else if(T->left && T->right) {
        TmpCell = FindMin(T->right);
        T->Element = TmpCell->Element;
        T->right = Delete(X, T->right);
    } else {
        TmpCell = T;
        if (T->left == NULL)
            T = T->right;
        else if(T->right = NULL)
            T = T->left;
        free(TmpCell);
    }
    return T;
}

ElementType Retrieve(Position P) {
    if(P == NULL)
        return -1;
    else
        return P->Element;
}

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}
