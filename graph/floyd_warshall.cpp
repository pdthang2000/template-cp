#include<bits/stdc++.h>
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
ll n, m, q, x, y, z;
void pdthang2000() {
	cin >> n >> m >> q;
	vector<vector<ll>> g(n + 1, vector<ll> (n + 1, LLONG_MAX / 2));
	for (ll i = 1; i <= n; ++i) {
		g[i][i] = 0;
	}
	for (ll i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = min(g[y][x], z); 
	}
	for (ll k = 1; k <= n; ++k) {
		for (ll i = 1; i <= n; ++i) {
			for (ll j = 1; j <= n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << (g[x][y] == LLONG_MAX / 2 ? -1 : g[x][y]) << '\n';
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
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

Input

The first input line has three integers n, m and q: the number of cities, roads, and queries.

Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.

Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output

Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1≤n≤500
1≤m≤n2
1≤q≤105
1≤a,b≤n
1≤c≤109
Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
*/
