/*************************************************************************
	> File Name: 102.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月25日 星期四 19时47分37秒
 ************************************************************************/

int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

void getColumns(struct TreeNode *root, int *cols, int k) {
    if (root == NULL) return ;
    cols[k] += 1;
    getColumns(root->left, cols, k + 1);
    getColumns(root->right, cols, k + 1);
    return ;
}

void getResult(struct TreeNode *root, int **ret, int *cols, int k) {
    if (root == NULL) return ;
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k + 1);
    getResult(root->right, ret, cols, k + 1);
    return ;
}

/*
 * 遇到*returnSize这样的形参时，可能是传入一个一维数组，也可能是一个传出参数，即在函数中改变实参的值
 * 遇到**columnSizes这样的形参时，可能是传入一个二维数组，也可能是一个传出参数，即在函数中改变一个一维数组的值
*/
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHeight(root);
    *columnSizes = (int *)calloc(sizeof(int), (*returnSize));
    getColumns(root, *columnSizes, 0);
    int **ret = (int  **)malloc(sizeof(int *) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[i]);
        (*columnSizes)[i] = 0;
    }
    getResult(root, ret, *columnSizes, 0);
    return ret;
}
