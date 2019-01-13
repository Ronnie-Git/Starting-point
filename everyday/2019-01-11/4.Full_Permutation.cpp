/*************************************************************************
	> File Name: test.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月11日 星期五 16时51分23秒
 ************************************************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void swap(int *num, int l, int r) {
    while (l < r) {
        int temp = num[l];
        num[l] = num[r];
        num[r] = temp;
        l++, r--;
    }
    return ;
}

int main() {
    int n, cut = 9, k = 0;
    char s[10] = {0}, t[10] = {0};
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //while (scanf("%s", s) != EOF) {
    scanf("%d", &n);
    while (--n) {
        for (int i = 9; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                cut = i;
                break;
            }
        }
        if (cut == 0) break;
        for (int i = 9; i >= cut; i--) {
            if (num[cut - 1] < num[i]) {
                int temp = num[cut-1];
                num[cut-1] = num[i];
                num[i] = temp;
                break;
            }
        }
        //sort(num + cut, num + 10);
        swap(num, cut, 9);
        /*
        for (int i = 0; i < 10; i++) {
            t[i] = num[i] + '0';
        }
        t[10] = '\0';
        if (strcmp(s, t) == 0) continue;
        printf("%s\n", s);
        */
    }
        for (int i = 0; i < 10; i++) {
            printf("%d", num[i]);
        }
        printf("\n");
    //}
    return 0;
}
