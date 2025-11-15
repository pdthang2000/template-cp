// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;

double signedArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double result = (
		x1 * (y2 - y3) +
		x2 * (y3 - y1) +
		x3 * (y1 - y2)
	) / 2.0;

	// result < 0, 3 points position: Counter clockwise
	// result > 0, 3 points position: Clockwise
	// result = 0, 3 points are placed on the same line

	return result;
}

double triangleArea(double x1, double y1,
                    double x2, double y2,
                    double x3, double y3) {
    return fabs(signedArea(x1, y1, x2, y2, x3, y3));
}


int main() {
	ios_base::sync_with_stdio(0);
	double x1 = 1, y1 = 1;
    double x2 = 4, y2 = 2;
    double x3 = 2, y3 = 5;

    double A = triangleArea(x1, y1, x2, y2, x3, y3);

    cout << "Triangle area = " << A << endl;
}