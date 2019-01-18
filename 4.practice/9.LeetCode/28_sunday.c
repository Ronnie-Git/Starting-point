/*************************************************************************
	> File Name: 28_sunday.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 18时50分59秒
 ************************************************************************/

#include <stdio.h>

int strStr(char *haystack, char *needle) {
    int len = 0;
    int pos[256] = {0};
    // memset按字节赋值 将每个字节都赋为同一个值 所以只能初始化为0或-1
    memset(pos, -1, sizeof(pos));
    for (; needle[len]; len++) pos[needle[len]] = len;
    int i = 0, len2 = strlen(haystack);
    while (i + len <= len2) {
        int j = 0;
        while (needle[j] && needle[j] == haystack[i + j]) ++j;
        if (needle[j] == 0) return i;
        i += (len - pos[haystack[i + len]]);
    }
    return -1;
}
