#include "stdc++.h"
// #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll n, m, x, y, z;
 
// lower second go to the top
struct cmp {
	bool operator() (pair<ll, ll> a, pair<ll, ll> b) {
		return a.second > b.second;
	}
};
 
vector<ll> dijkstra(ll start_point, ll n, vector<pair<ll, ll>> g[]) {
	vector<bool> used(n + 1, 0);
	vector<ll> d(n + 1, LLONG_MAX);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> Q;
	
	d[start_point] = 0;

	Q.push({start_point, d[start_point]});
	
	while (Q.size()) {
		ll cur = Q.top().first;
		Q.pop();
		if (used[cur]) continue;	
		used[cur] = 1;
		for (auto i: g[cur]) {
            ll destination = i.first;
            ll distance = i.second;
			if (d[destination] > d[cur] + distance) {
				d[destination] = d[cur] + distance;
				Q.push({destination, d[destination]});
			}
		}
	}
	return d;
}
void pdthang2000() {
	cin >> n >> m;
	vector<pair<ll, ll>> g[MAX_N];
	for (ll i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		g[x].push_back({y, z});
	}
	vector<ll> res = dijkstra(1, n, g);
 
	for (ll i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	if (MULTI_TESTS) {
		ll Q;
		cin >> Q;
		while (Q--) {
			pdthang2000();
			qq;
		}
	} else {
		pdthang2000();
	}
}
/*
There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.

Input

The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n, and city 1 is Syrjälä.

After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.

You can assume that it is possible to travel from Syrjälä to all other cities.

Output

Print n integers: the shortest route lengths from Syrjälä to cities 1,2,…,n.

Constraints
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
1≤c≤109
Example

Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
*/
