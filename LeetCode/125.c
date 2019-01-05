/*************************************************************************
	> File Name: 125.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月05日 星期六 16时57分06秒
 ************************************************************************/

bool isPalindrome(char* s) {
    char *temp = (char *)malloc(sizeof(char) * strlen(s));
    int len = 0;
    for (int i = 0; s[i]; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                temp[len++] = s[i] + 32;
            } else {
                temp[len++] = s[i];
            }
        }
    }
    int l = 0, r = len - 1, flag = 1;
    //printf("%s\n", temp);
    while (l <= r) {
        if (temp[l] != temp[r]) {
            flag = 0;
            break;
        }
        l++, r--;
    }
    free(temp);
    if (flag) return true;
    return false;
}
