/*************************************************************************
	> File Name: 165.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月13日 星期日 19时50分06秒
 ************************************************************************/

int compareVersion(char* version1, char* version2) {
    int i = -1, j = -1;
    int len1 = strlen(version1), len2 = strlen(version2);
    do {
        if (i < len1) ++i;
        if (j < len2) ++j;
        int temp1 = 0, temp2 = 0;
        while (version1[i] && version1[i] != '.') {
            temp1 = temp1 * 10 + (version1[i] - '0');
            i++;
        }
        while (version2[j] && version2[j] != '.') {
            temp2 = temp2 * 10 + (version2[j] - '0');
            j++;
        }
        if (temp1 > temp2) return 1;
        if (temp1 < temp2) return -1;
    } while (version1[i] || version2[j]);
    return 0;
}
