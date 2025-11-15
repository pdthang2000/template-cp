#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
	ios_base::sync_with_stdio(0);
    int x1 = 1, y1 = 8;
    int x2 = 4, y2 = 6;

    cout << distance(x1, y1, x2, y2) << '\n';

	int a = 1, b = 3;
	int c = 1, d = 5;

	cout << distance(a, b, c, d) << '\n';
}