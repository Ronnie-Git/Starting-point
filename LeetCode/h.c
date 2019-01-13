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
    int i = 0, j = 0;
    do {
        int temp1 = 0, temp2 = 0;
        while (version1[i] != '.' && version1[i]) {
            temp1 = temp1 * 10 + (version1[i++] - '0');
        }
        while (version2[j] != '.' && version2[j]) {
            temp2 = temp2 * 10 + (version2[j++] - '0');
        }
        if (temp1 > temp2) return 1;
        if (temp1 < temp2) return -1;
        i++, j++;
    } while (version1[i] && version2[j]);
    if (version1[i] == version2[j]) return 0;
    return version1[i] ? 1 : -1;
}

int main() {
    char str1[100] = {0}, str2[100] = {0};
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d\n", compareVersion(str1, str2));
    return 0;
}
