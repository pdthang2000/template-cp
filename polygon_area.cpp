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
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
double cal_area(ll n, vector<double> x, vector<double> y) {
	double area = 0.0;
	x[n] = x[0];
	y[n] = y[0];
	for (ll i = 0; i < n; ++i) {
		area += x[i] * y[i + 1] - x[i + 1] * y[i]; 
	}
	return abs(area);
    return abs(area) / 2.0; // in case we need the right area, normally we will get abs(res) for less different.
}
 
double polygon_area(ll n, vector<double> x, vector<double> y)
{
    // Initialize area
    double area = 0.0;
  
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;  // j is previous vertex to i
    }
  
    // Return absolute value
    return abs(area);
    return abs(area / 2.0);
}
void pdthang2000() {
	ll n;
	cin >> n;
	vector<ll> x(n + 1), y(n + 1);
	for (ll i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	x[n] = x[0], y[n] = y[0];
	ll area = 0;
	for (ll i = 0; i < n; ++i) {
		area += x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	cout << abs(area);
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
Polygon Area

Time limit: 1.00 s Memory limit: 512 MB
Your task is to calculate the area of a given polygon.

The polygon consists of n vertices (x1,y1),(x2,y2),…,(xn,yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent for i=1,2,…,n−1, and the vertices (x1,y1) and (xn,yn) are also adjacent.

Input

The first input line has an integer n: the number of vertices.

After this, there are n lines that describe the vertices. The ith such line has two integers xi and yi.

You may assume that the polygon is simple, i.e., it does not intersect itself.

Output

Print one integer: 2a where the area of the polygon is a (this ensures that the result is an integer).

Constraints
3≤n≤1000
−109≤xi,yi≤109
Example

Input:
4
1 1
4 2
3 5
1 4

Output:
16
*/