/*************************************************************************
	> File Name: 13.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月05日 星期六 14时49分40秒
 ************************************************************************/

void init(int *num) {
    num['I'] = 1;
    num['V'] = 5;
    num['X'] = 10;
    num['L'] = 50;
    num['C'] = 100;
    num['D'] = 500;
    num['M'] = 1000;
    return ;
}

int romanToInt(char* s) {
    int num[128] = {0};
    init(num);
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (i > 0 && num[s[i - 1]] < num[s[i]]) ans -= 2 * num[s[i - 1]];
        ans += num[s[i]];
    }
    return ans;
}
