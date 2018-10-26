/*************************************************************************
	> File Name: 107.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年10月26日 星期五 16时30分38秒
 ************************************************************************/

int getHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left), r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}

void getColumns(struct TreeNode *root, int *cols, int k) {
    if (root == NULL) return ;
    if (k < 0) return ;
    cols[k] += 1;
    getColumns(root->left, cols, k - 1);
    getColumns(root->right, cols, k - 1);
    return ;
}

void getResult(struct TreeNode *root, int **ret, int *cols, int k) {
    if (root == NULL) return ;
    if (k < 0) return ;
    ret[k][cols[k]++] = root->val;
    getResult(root->left, ret, cols, k - 1);
    getResult(root->right, ret, cols, k - 1);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = getHeight(root);
    *columnSizes = (int *)calloc(sizeof(int), (*returnSize));
    getColumns(root, *columnSizes, *returnSize - 1);
    int **ret = (int  **)malloc(sizeof(int *) * (*returnSize));
    for (int i = *returnSize - 1; i >= 0; i--) {
        ret[i] = (int *)malloc(sizeof(int) * (*columnSizes)[i]);
        (*columnSizes)[i] = 0;
    }
    getResult(root, ret, *columnSizes, *returnSize - 1);
    return ret;   
}
