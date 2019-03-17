/*************************************************************************
	> File Name: 38.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月15日 星期四 19时33分22秒
 ************************************************************************/

char* countAndSay(int n) {
    if (n == 1) return strdup("1");
    char *s = countAndSay(n - 1);
    int len = 1;
    for (int i = 1; s[i]; i++) len += (s[i] != s[i - 1]);
    len = len << 1 + 1;
    char *ret = (char *)calloc(sizeof(char), len);
    int num = s[0] - '0', cnt = 1, j = 0;
    for (int i = 1; s[i - 1]; i++) {
        if (s[i] == s[i - 1]) {
            cnt += 1;
        } else {
            j += sprintf(ret + j, "%d%d", cnt, num);
            cnt = 1;
            num = s[i] - '0';
        }
    }
    free(s);
    return ret;
}
