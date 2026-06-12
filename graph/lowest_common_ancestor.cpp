// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define cer(x) cerr << #x << " = " << x << ' ';
#define cern(x) cerr << #x << " = " << x << '\n';
#define cc cerr << '\n';
const bool MULTIPLE_QUERY = 0;
const ll MAX_N = 200'005;
const ll MOD = 1e9 + 7;
const ll LOG = 18;

int depth[MAX_N];
int up[MAX_N][LOG];
int g[MAX_N];

auto __fast_io_atexit = []() { 
    ios::sync_with_stdio(0); 
	cin.tie(0);
    return 0; 
}();
/*
    1   up[1][0] = 0
    |
    2   up[2][0] = 1, up[2][1] = 0
    |
    3   up[3][0] = 2, up[3][1] = 1
    |
    4   up[4][0] = 3, up[4][1] = 2
    |
    5   up[5][0] = 4, up[5][1] = 3, up[5][2] = 1

    up[v][k] = up[ up[v][k - 1] ][k - 1];

    up[5][0] = 4
    up[5][1] = up[4][0] = 3

<=> up[ up[5][0] ][ 0 ] = 3

    up[5][2] = up[4][1] = 1
    up[5][2] = up[ up[5][1] ][ 1 ] = up[3][1] = 1
*/
void dfs(int cur, int parent) {
    up[cur][0] = parent;
    for (int i = 1; i < LOG; ++i) {
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    }

    for (auto child: g[cur]) {
        if (child == parent) continue;
        dfs(child, cur);
        depth[child] = depth[cur] + 1;
    }
}

void build_lca(int root) {
    depth[root] = 1;
    dfs(root, 0); // node 0 is the sentinel (non-existent)
}

int lca(int u, int v) {
    // Bring u and v to the same depth
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for (int k = 0; k < LOG; ++k) {
        if ((diff >> k) & 1) {
            u = up[u][k];
        }
    }
    if (u == v) return u;

    // Lift both until their ancestors diverge

    // Think of it like a cashier giving change. You owe someone 6 baht change. 
    // You don't hand them 6 individual 1-baht coins — you give the biggest coin that fits first.
    // 6 = 4 + 2
    // → give 4-baht coin first, then 2-baht coin
    // Binary lifting does the same. You try the biggest jump first, commit if it's safe, then refine with smaller jumps.    
    
    for (int k = LOG - 1; k >= 0; --k) {
    // If up[u][k] == up[v][k], that means jumping would land both of them at or above the LCA — either on the LCA itself, or past it. 
    // Either way, overshooting. So you skip.
        if (up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }

    // After the loop, u and v are the two nodes immediately below the LCA — one on each branch. 
    // They're different from each other, but share the same parent.
    
    //     LCA          ← up[u][0] = up[v][0] = LCA
    //     / \
    //    u   v         ← where the loop leaves you

    return up[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void solve() {
    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    build_lca(1);
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}


int main() {
	if (MULTIPLE_QUERY) {
		ll Q;
		cin >> Q;
		while (Q--) {
			solve(); 
			qq;
		}
	} else {
		solve();
	}
}

/*
Input:
7 3
1 2
1 3
2 4
2 5
3 6
3 7
4 5
5 6
6 7
 
Output:
2
1
3
 
Explanation:
        1
       / \
      2   3
     / \ / \
    4  5 6  7
 
lca(4, 5) = 2
lca(5, 6) = 1
lca(6, 7) = 3
*/