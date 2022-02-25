#include <bits/stdc++.h>
#define NAME "convex."
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
 
using namespace std; 
 
typedef pair <double, double> pdd;
// ifstream cin (NAME"inp"); ofstream cout (NAME"out");
ll n;
double area(pdd a, pdd b, pdd c) {
	return (
		a.first * (b.second - c.second) +
		b.first * (c.second - a.second) +
		c.first * (a.second - b.second)
	) / 2;
}
vector<pdd> get_convex_hull(vector<pdd> a) {
	vector<pdd> up, down;
	sort(a.begin(), a.end());
	pdd p1 = a[0], p2 = a[n-1];
	up.push_back(p1); 
	down.push_back(p1);
	for (ll i = 1; i < a.size(); ++i) {
		if (i == a.size() - 1 || area(p1, a[i], p2) <= 0) {
			while (up.size() >= 2 && 
				area(up[up.size() - 2], up[up.size() - 1], a[i]) > 0) up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || area(p1, a[i], p2) >= 0) {
			while (down.size() >= 2 &&
				area(down[down.size() - 2], down[down.size() - 1], a[i]) < 0) down.pop_back();
			down.push_back(a[i]);
		}
	}
	vector<pdd> res;
	for (ll i = 0; i < up.size(); ++i) res.push_back(up[i]);
	for (ll i = down.size() - 2; i > 0; --i) res.push_back(down[i]);
	return res; 
}
int main() {
	cin >> n;
	vector<pdd> a(n);
	for (ll i = 0; i < n; ++i) cin  >> a[i].first >> a[i].second;
 
	vector<pdd> convex_hull = get_convex_hull(a);
	
	cout << convex_hull.size() << '\n';
	for (auto i : convex_hull) {
		cout << (ll)i.first << ' ' << (ll)i.second << '\n';
	}
}
