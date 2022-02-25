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
ll n, m;
vector<ll> x, y;
bool c_inside_a_and_b(ll a1, ll a2, ll b1, ll b2, ll c1, ll c2) {
	return (
		min(a1, b1) <= c1 && c1 <= max(a1, b1) &&
		min(a2, b2) <= c2 && c2 <= max(a2, b2)
	);
	/*
	a1 = 1, a2 = 4, 
	b1 = 1, b2 = 3,
	c1 = 1, c2 = 1,
	*/
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
 
bool intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double case_1 = area(x1, y1, x2, y2, x3, y3);
	double case_2 = area(x1, y1, x2, y2, x4, y4);
	double case_3 = area(x3, y3, x4, y4, x1, y1);
	double case_4 = area(x3, y3, x4, y4, x2, y2);
	
	if (case_1 != case_2 && case_3 != case_4) {
		return 1;
	}
	if (case_1 == 0 && c_inside_a_and_b(x1, y1, x2, y2, x3, y3)) {
		return 1;
	}
	if (case_2 == 0 && c_inside_a_and_b(x1, y1, x2, y2, x4, y4)) {
		return 1;
	}
	if (case_3 == 0 && c_inside_a_and_b(x3, y3, x4, y4, x1, y1)) {
		return 1;
	}
	if (case_4 == 0 && c_inside_a_and_b(x3, y3, x4, y4, x2, y2)) {
		return 1;
	}
	return 0;
}
 
string p_to_poligon(double px, double py) {
	double inf = MOD * 2;
	ll cnt = 0;
	for (ll i = 0; i < n; ++i) {
		ll next = (i + 1) % n;
		if (intersect(x[i], y[i], x[next], y[next], px, py, inf, py + 0.01)) {
			if (area(x[i], y[i], x[next], y[next], px, py) == 0) {
				if (c_inside_a_and_b(x[i], y[i], x[next], y[next], px, py)) {
					return "BOUNDARY";
				} else {
					return "OUTSIDE";
				}
			}
			cnt++;
		}
	}
	return (cnt & 1 ? "INSIDE" : "OUTSIDE");
}
 
void pdthang2000() {
	double px, py;
	cin >> n >> m;
	for (ll i = 0; i < n; ++i) {
		cin >> px >> py;
		// cout << "(" << px << ", " << py << "), \n"; 
		x.push_back(px);
		y.push_back(py);
	}
 
	while (m--) {
		cin >> px >> py;
		cout << p_to_poligon(px, py) << '\n';
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
Point in Polygon

Time limit: 1.00 s Memory limit: 512 MB
You are given a polygon of n vertices and a list of m points. Your task is to determine for each point if it is inside, outside or on the boundary of the polygon.

The polygon consists of n vertices (x1,y1),(x2,y2),…,(xn,yn). The vertices (xi,yi) and (xi+1,yi+1) are adjacent for i=1,2,…,n−1, and the vertices (x1,y1) and (xn,yn) are also adjacent.

Input

The first input line has two integers n and m: the number of vertices in the polygon and the number of points.

After this, there are n lines that describe the polygon. The ith such line has two integers xi and yi.

You may assume that the polygon is simple, i.e., it does not intersect itself.

Finally, there are m lines that describe the points. Each line has two integers x and y.

Output

For each point, print "INSIDE", "OUTSIDE" or "BOUNDARY".

Constraints
3≤n,m≤1000
1≤m≤1000
−109≤xi,yi≤109
−109≤x,y≤109
Example

Input:
4 3
1 1
4 2
3 5
1 4
2 3
3 1
1 3

Output:
INSIDE
OUTSIDE
BOUNDARY
*/