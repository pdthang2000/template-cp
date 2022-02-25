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
 
bool c_inside_a_and_b(ll a1, ll a2, ll b1, ll b2, ll c1, ll c2) {
	return (
		min(a1, b1) <= c1 && c1 <= max(a1, b1) &&
		min(a2, b2) <= c2 && c2 <= max(a2, b2)
	);
}
 
ll area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double res = (
		x1 * (y2 - y3) + 
		x2 * (y3 - y1) +
		x3 * (y1 - y2)
	) / 2;
 
	if (res == 0) return 0;
	return (res > 0 ? 1 : -1);
}
 
void pdthang2000() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
 
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	double case_1 = area(x1, y1, x2, y2, x3, y3);
	double case_2 = area(x1, y1, x2, y2, x4, y4);
	double case_3 = area(x3, y3, x4, y4, x1, y1);
	double case_4 = area(x3, y3, x4, y4, x2, y2);
	
	if (case_1 != case_2 && case_3 != case_4) {
		cout << "YES";
		return;
	}
	if (case_1 == 0 && c_inside_a_and_b(x1, y1, x2, y2, x3, y3)) {
		cout << "YES";
		return;
	}
	if (case_2 == 0 && c_inside_a_and_b(x1, y1, x2, y2, x4, y4)) {
		cout << "YES";
		return;
	}
	if (case_3 == 0 && c_inside_a_and_b(x3, y3, x4, y4, x1, y1)) {
		cout << "YES";
		return;
	}
	if (case_4 == 0 && c_inside_a_and_b(x3, y3, x4, y4, x2, y2)) {
		cout << "YES";
		return;
	}
	cout << "NO";
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
Line Segment Intersection

Time limit: 1.00 s Memory limit: 512 MB
There are two line segments: the first goes through the points (x1,y1) and (x2,y2), and the second goes through the points (x3,y3) and (x4,y4).

Your task is to determine if the line segments intersect, i.e., they have at least one common point.

Input

The first input line has an integer t: the number of tests.

After this, there are t lines that describe the tests. Each line has eight integers x1, y1, x2, y2, x3, y3, x4 and y4.

Output

For each test, print "YES" if the line segments intersect and "NO" otherwise.

Constraints
1≤t≤105
−109≤x1,y1,x2,y2,x3,y3,x4,y4≤109
(x1,y1)≠(x2,y2)
(x3,y3)≠(x4,y4)
Example

Input:
5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4

Output:
NO
YES
YES
YES
YES

*/