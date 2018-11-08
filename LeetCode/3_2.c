/*************************************************************************
	> File Name: 3_2.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 19时08分00秒
 ************************************************************************/

int lengthOfLongestSubstring(char* s) {
    int pos[256], len = 0, ans = 0;
    memset(pos, -1, sizeof(pos));
    for (int i = 0; s[i]; i++) {
        len += 1;
        if (i - pos[s[i]] < len) len = i - pos[s[i]];
        pos[s[i]] = i;
        if (len > ans) ans = len;
    }
    return ans;
}
