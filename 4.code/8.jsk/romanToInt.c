/*************************************************************************
	> File Name: romanToInt.c
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月05日 星期六 15时01分25秒
 ************************************************************************/

#include<stdio.h> 
#include<string.h>

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

int main() {
    int num[128] = {0};
    init(num);
	char str[1000] = {0};
	while(scanf("%s", str) != EOF) {
		int ans = 0;
    	for (int i = 0; str[i]; i++) {
        	if (i > 0 && num[str[i - 1]] < num[str[i]]) ans -= 2 * num[str[i - 1]];
        	ans += num[str[i]];
   		}
		printf("%d\n", ans);
	}
	return 0;
} 

