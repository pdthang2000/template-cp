#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 1;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
 
double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (
		x1 * (y2 - y3) + 
		x2 * (y3 - y1) +
		x3 * (y1 - y2)
	) / 2;
}
 
void pdthang2000() {
	double x1, y1, x2, y2, x3, y3;
 
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double res = area(x1, y1, x3, y3, x2, y2);
	if (res == 0) {
		cout << "TOUCH";
		return;
	}
	if (res < 0) {
		cout << "LEFT";
		return;
	}
	if (res > 0) {
		cout << "RIGHT";
		return;
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	if (MULTI_TESTS) {
		ll Q;
		cin >> Q;
		while (Q--) {
			pdthang2000();
			endl;
		}
	} else {
		pdthang2000();
	}
}

/*
Point Location Test

Time limit: 1.00 s Memory limit: 512 MB

There is a line that goes through the points p1=(x1,y1) and p2=(x2,y2). There is also a point p3=(x3,y3).

Your task is to determine whether p3 is located on the left or right side of the line or if it touches the line when we are looking from p1 to p2.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines that describe the tests. Each line has six integers: x1, y1, x2, y2, x3 and y3.

Output

For each test, print "LEFT", "RIGHT" or "TOUCH".

Constraints
1≤t≤105
−109≤x1,y1,x2,y2,x3,y3≤109
x1≠x2 or y1≠y2
Example

Input:
3
1 1 5 3 2 3
1 1 5 3 4 1
1 1 5 3 3 2

Output:
LEFT
RIGHT
TOUCH

*/