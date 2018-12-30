/*************************************************************************
	> File Name: p1200.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年08月29日 星期三 11时40分36秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main(){
	int x = 1, y = 1, i;
	char str1[7], str2[7];
	scanf("%s", str1);
	scanf("%s", str2);
	for (i = 0; i < strlen(str1); i++) {
		str1[i] = str1[i] - 64;
		x = x * str1[i];
	}
	for (i = 0; i < strlen(str2); i++) {
		str2[i] = str2[i] - 64;
		y = y * str2[i];
	}
	if (x % 47 == y % 47) {
		printf("GO");
	} else {
		printf("STAY");
	}
	return 0;
} 
