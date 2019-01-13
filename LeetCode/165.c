/*************************************************************************
	> File Name: 165.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 19时50分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int compareVersion(char* version1, char* version2) {
    while (str1 && str2) {
        int temp1 = atoi(str1), temp2 = atoi(str2);
        printf("%d %d\n", temp1, temp2);
        if (temp1 > temp2) return 1;
        if (temp1 < temp2) return -1;
        str1 = strtok(str1, ".");
        str2 = strtok(str2, ".");
    }
    if (str1 == str2) return 0;
    return str1 ? 1 : -1;
}

int main() {
    char str1[100] = {0}, str2[100] = {0};
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d\n", compareVersion(str1, str2));
    return 0;
}
