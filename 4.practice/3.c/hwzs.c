/*************************************************************************
	> File Name: hwzs.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月10日 星期一 20时37分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 1000000
int s[N];

void num() {
	int j = 3, d1, d2, d3, d4;
	s[0] = 5, s[1] = 7, s[2] = 11;
	for (d1 = 1; d1 <= 9; d1+=2) {
     	for (d2 = 0; d2 <= 9; ++d2) {
        		s[j++] = 100*d1 + 10*d2 + d1;
    	}	
	}
	for (d1 = 1; d1 <= 9; d1+=2) {
     	for (d2 = 0; d2 <= 9; ++d2) {
        	 for (d3 = 0; d3 <= 9; ++d3) {
        		s[j++] = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
        	}
    	}	
	}
	for (d1 = 1; d1 <= 9; d1+=2) {
     	for (d2 = 0; d2 <= 9; ++d2) {
        	 for (d3 = 0; d3 <= 9; ++d3) {
        	 	for (d4 = 0; d4 <= 9; ++d4) {
        			s[j++] = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
        		}
			}
    	}	
	}
}

int prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (!(x % i)) return 0;
	}
	return 1;
}

int main() {
	int a, b;
	num();
	scanf("%d %d", &a, &b);
	for (int i = 0; i < 1000000; ++i) {
		if (s[i] > b) break;
		if (s[i] < a) continue;
		if (prime(s[i])) printf("%d\n", s[i]);
	}
	return 0;
} 
