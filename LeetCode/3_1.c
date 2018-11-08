/*************************************************************************
	> File Name: 3_1.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 18时53分01秒
 ************************************************************************/

int lengthOfLongestSubstring(char* s) {
    int *str = (int *)calloc(sizeof(int), 300);
    int n = strlen(s), i = 0, l = 0, ans = 0;
    while (i < n) { 
        !str[s[i]] ? (str[s[i++]] = 1) : (str[s[l++]] = 0);
        ans = (i - l) > ans ? (i - l) : ans;
    }
    free(str);
    return ans;
}
