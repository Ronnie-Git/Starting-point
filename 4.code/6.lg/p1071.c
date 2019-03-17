/*************************************************************************
	> File Name: p1071.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月06日 星期日 20时21分15秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char arr1[128] = {0}, arr2[128] = {0};
    char s1[100] = {0}, s2[100] = {0}, str[100] = {0};
    int flag = 1, cnt = 0;
    scanf("%s %s %s", s1, s2, str);
    for (int i = 0; s1[i]; i++) {
        if (arr1[s1[i]] == 0 && arr2[s2[i]] == 0) {
            arr1[s1[i]] = s2[i];
            arr2[s2[i]] = s1[i];
            cnt++;
        }
        if (arr1[s1[i]] != s2[i] || arr2[s2[i]] != s1[i]) {
            flag = 0;
            break;
        }
    }
    if (cnt != 26) flag = 0;
    for (int i = 0; flag && str[i]; i++) {
        str[i] = arr1[str[i]];
    }
    printf("%s\n", flag ? str : "Failed");
    return 0;
}
