#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double func(double x) {
    return 8*pow(x, 4) + 7*pow(x, 3) + 2*pow(x, 2) + 3*x + 6;
}

double solve(int y, double l, double r) {
    #define EPS 1e-5
    double mid, temp;
    while (l < r) {
    	mid = (l + r) / 2;
    	temp = func(mid);
    	if (fabs(y - temp) < EPS) return mid;
    	if (y > temp) l = mid;
    	else r = mid;
	}
	return mid;
}

int main() {
    int t, y;
    cin >> t;
    while (t--) {
        cin >> y;
        if (y < func(0) || y > func(100)) {
            cout << "No solution!" << endl;
        } else {
			printf("%.4lf\n", solve(y, 0, 100));
        }
    }
    return 0;
}
