/*************************************************************************
	> File Name: 48.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 17时13分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int num[20] = {0};
int dnum[20] = {0};

void jnum(int x) { // 计算阶乘的后十位数
    memset(dnum, 0, sizeof(dnum));
    dnum[0] = dnum[1] = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= 10; j++) dnum[j] *= x;
        for (int j = 1; j <= 10; j++) {
            if (dnum[j] < 10) continue;
            dnum[j + 1] += dnum[j] / 10;
            dnum[j] = dnum[j] % 10;
        }
        dnum[11] = 0;
    }
}

int main() {
    for (int i = 1; i < 1001; i++) {
        jnum(i);
        for (int j = 1; j <= 10; j++) num[j] += dnum[j];
        for (int j = 1; j <= 10; j++) { // 计算阶乘求和的后十位数
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] = num[j] % 10;
        }
        num[11] = 0;
    }
    for (int i = 10; i > 0; i--) printf("%d", num[i]);
    printf("\n");
    return 0;
}
