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
/*
Pick's formula : 
Area = i + (b / 2) - 1;
 
i = number of integer points that are interior to the polygon
b = the number of integer points on its boundary 
*/
 
void pdthang2000() {
	ll n;
	cin >> n;
	vector<ll> x(n + 1), y(n + 1);
	for (ll i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	x[n] = x[0], y[n] = y[0];
	ll area = 0;
	ll borders = 0;	
	for (ll i = 0; i < n; ++i) {
		area += x[i] * y[i + 1] - x[i + 1] * y[i];
 
		borders += abs(__gcd(x[i + 1] - x[i], y[i + 1] - y[i]));
	}
	ll a = abs(area) - borders + 2;
	// real area = abs(area) / 2, but with the equation below we use 2A, so we dont have to divide 2. 
	// 2A = 2i + b - 2
	// <=> 2i = 2A - b + 2
	// <=> i = (2A - b + 2) / 2
	cout << a / 2 << ' ' << borders;
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
Polygon Lattice Points

Time limit: 1.00 s Memory limit: 512 MB
Given a polygon, your task is to calculate the number of lattice points inside the polygon and on its boundary. A lattice point is a point whose coordinates are integers.

The polygon consists of n vertices (x1,y1),(x2,y2),…,(xn,yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent for i=1,2,…,n−1, and the vertices (x1,y1) and (xn,yn) are also adjacent.

Input

The first input line has an integer n: the number of vertices.

After this, there are n lines that describe the vertices. The ith such line has two integers xi and yi.

You may assume that the polygon is simple, i.e., it does not intersect itself.

Output

Print two integers: the number of lattice points inside the polygon and on its boundary.

Constraints
3≤n≤105
−106≤xi,yi≤106
Example

Input:
4
1 1
5 3
3 5
1 4

Output:
6 8
*/
