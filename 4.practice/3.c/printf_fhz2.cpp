/*************************************************************************
	> File Name: lx2.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月21日 星期二 09时53分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        FILE *fout = fopen("/dev/null", "w");
        printf("%d has %d digits\n", n, fprintf(fout, "%d", n));
    } 
    /*while (scanf("%d", &n) != EOF) {
        printf(" has %d digits\n", printf("%d", n));
    }*/
    return 0;
}
