/*************************************************************************
	> File Name: 3_3.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月08日 星期四 19时21分47秒
 ************************************************************************/

int check(char *s, int len) {
    if (len == 0) return 1;
    int num[256] = {0}, cnt = 0;
    for (int i = 0; s[i]; i++) {
        num[s[i]] += 1;
        cnt += (num[s[i]] == 1);
        if (i >= len) {
            num[s[i - len]]--;
            cnt -= (num[s[i - len]] == 0);
        }
        if (cnt == len) return 1;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}
