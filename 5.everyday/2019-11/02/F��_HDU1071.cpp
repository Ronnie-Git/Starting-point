#include <iostream>
#include <cstdio>
using namespace std;

double k, b, a, h, c; 
// 抛物线：y = a*(x-h)^2 + c
// 直线：  y = k*x + b 

double solve(double x) {
	return (a/3*x*x*x - (2*a*h+k)/2*x*x + (a*h*h+c-b)*x);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		k = (y3-y2) / (x3-x2);
		b = y2 - k*x2;
		
		h = x1, c = y1;
		a = (y2-c) / ((x2-h)*(x2-h));
		
		printf("%.2lf\n", solve(x3) - solve(x2)); 
	}
	return 0;
}
