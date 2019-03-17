/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月13日 星期四 18时45分50秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    //fprintf
    //sprintf 会在末尾加\0

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", fprintf(fout, "%d", n));
    }    
    
    /*while (scanf("%d", &n) != EOF) {
        printf("%d\n", sprintf(str, "%d", n));
        //printf("%s\n", str);
        for (int i = 1, j = 0; i <= 20; i++) {
            j += sprintf(str + j, "%d", i);
        }
        printf("%s\n", str);
    }*/

    /*while (scanf("%d", &n) != EOF) {
        printf(" has %d digits\n", printf("%d", n));
    }*/
    return 0;
}
