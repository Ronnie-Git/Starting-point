/*************************************************************************
	> File Name: 378_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 20时55分34秒
 ************************************************************************/

#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}

void _sort(int *num, int n) {
    for (int j = n - 2; j >= 0; j--) {
        if (num[j] > num[j + 1]) {
            swap(num[j], num[j + 1]);
        } else {
            break;
        }
    }
    return ;
}

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    int *num = (int *)malloc(sizeof(int) * (k + 5));
    int cnt = 0;
    for (int i = 0; i < matrixColSize; i++) {
        for (int j = 0; j < matrixRowSize; j++) {
            if (cnt <= k) {
                num[cnt++] = matrix[i][j];
                if (i) _sort(num, cnt);
                continue;
            }
            num[k] = matrix[i][j];
            _sort(num, k + 1);
        }
    }
    int ans = num[k - 1];
    free(num);
    return ans;
}
