/*************************************************************************
	> File Name: 26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时02分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int dnum[100000] = {0};

int get_length(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    printf("1 / %d = 0.", d);
    while (y != 0 && dnum[y] == 0) { // 输出小数
        printf("%d", y * 10 / d);
        dnum[y] = n;
        y = y * 10 % d;
        n += 1;
    }
    printf("(%d)\n", y ? n - dnum[y] : 0); // 输出循环个数
    return y ? n - dnum[y] : 0;
}

int main() {
    int max_length = 0, ans = 0;
    for (int d = 2; d < 1000; d++) {
        int temp_length = get_length(d);
        if (temp_length  > max_length) {
            max_length = temp_length;
            ans = d;
        }
    }
    printf("%d -> %d\n", ans, max_length);
    return 0;
}
