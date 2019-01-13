/*************************************************************************
	> File Name: 28_KMP.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 18时58分35秒
 ************************************************************************/

#include <stdio.h>

int strStr(char* haystack, char* needle) {
    if (strlen(needle) == 0) return 0;
    int *next = (int *)malloc(sizeof(int) * strlen(needle));
    next[0] = -1;
    for (int i = 1; needle[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && needle[j + 1] != needle[i]) j = next[j];
        if (needle[j + 1] == needle[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (haystack[i]) {
        while (j != -1 && haystack[i] != needle[j + 1]) j = next[j];
        if (haystack[i] == needle[j + 1]) {
            j += 1;
        }
        i += 1;
        if (needle[j + 1] == 0) return i - strlen(needle);
    }
    return -1;
}
