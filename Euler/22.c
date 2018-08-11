/*************************************************************************
	> File Name: 22.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 09时42分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include "EP22_1.h"

void sort() {
    int k = 0;
    while (strlen(Name[k++]) != 0);
    for (int i = 0; i < k - 2; i++) {
        for (int j = i + 1; j < k - 1; j++) {
            if (strcmp(Name[i], Name[j]) <= 0) continue;
            char t[20];
            strcpy(t, Name[i]);
            strcpy(Name[i], Name[j]);
            strcpy(Name[j], t);
        }
    }
}

int main() {
    int i = 0, sum = 0, ans = 0;
    sort();
    for (i = 0; strlen(Name[i]); i++) {
        for (int j = 0; j < strlen(Name[i]); j++) {
            ans += (Name[i][j] - 'A' + 1);
        }
        sum += (i + 1) * ans;
        ans = 0;
    }
    printf("%d\n", sum);
}
