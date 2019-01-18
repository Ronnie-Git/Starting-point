/*************************************************************************
	> File Name: 38_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 20时04分11秒
 ************************************************************************/

char* countAndSay(int n) {
    char *str = (char *)calloc(sizeof(char), 10000);
    char *ans = (char *)calloc(sizeof(char), 10000);
    str[0] = '1';
    if (n == 1) return str;
    int sum = 0, j = 0;
    char k = str[0];
    while (--n) {
        sum = 0, j = 0, k = str[0];
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == k) {
                sum++;
            } else {
                ans[j++] = sum + '0';
                ans[j++] = k;
                k = str[i];
                sum = 1;
            }
        }
        ans[j++] = sum + '0';
        ans[j++] = k;
        strcpy(str, ans);
    }
    free(str);
    return ans;
}
