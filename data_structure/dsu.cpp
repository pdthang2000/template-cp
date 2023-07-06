
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll parent[MAX_N], sz[MAX_N];

ll find_set(ll x) {
    if (x != parent[x]) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_set(ll u, ll v) {
    u = find_set(u);
    v = find_set(v);
    if (sz[u] < sz[v]) swap(u, v);
    if (u != v) {
        sz[u] += sz[v];
        parent[v] = u;
    }
}
void pdthang2000() {
    ll n, m, u, v;
    string s;
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) parent[i] = i;
    while (m--) {
        cin >> s >> u >> v;
        if (s == "union") {
            union_set(u, v);
        } else {
            u = find_set(u);
            v = find_set(v);
            cout << (u == v ? "YES\n" : "NO\n");
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pdthang2000();
}
/*
input
4 4
union 1 2
union 1 3
get 1 4
get 2 3

output
NO
YES
*/