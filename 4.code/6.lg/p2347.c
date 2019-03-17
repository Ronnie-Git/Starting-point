/*************************************************************************
	> File Name: p2347.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月22日 星期六 15时59分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int num[10] = {0}, fm[6] = {1, 2, 3, 5, 10, 20}, ans[1005] = {0}, sum = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 6; i++) {
        if (num[i] == 0) continue;
        for (int j = 1; j <= 1000; j++) {
            if (ans[j] == 0 || ans[j] == fm[i]) continue;
            for (int l = 1; l <= num[i]; l++) {
                int ind = l * fm[i] + j;
                if (!ans[ind]) ans[ind] = fm[i];
            }
        }
        for (int j = 1; j <= num[i]; j++) {
            ans[j * fm[i]] = fm[i];
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (ans[i]) sum++;
    }
    printf("Total=%d\n", sum);
    return 0;
}
