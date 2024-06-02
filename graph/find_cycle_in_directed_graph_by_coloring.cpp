#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
ll used[100005], color[100005];
const ll UN_VISITED = 0;
const ll VISITING = 1;
const ll VISITED = 2;

vector<vector<ll>> adj;
vector<ll> parent, cost, cycle;

bool res_found = false;

void get_cycle(ll start_v, ll end_v) {
    cycle.push_back(start_v);

    while (start_v != end_v) {
        cycle.push_back(end_v);
        end_v = parent[end_v];
    }

    cycle.push_back(start_v);

    reverse(cycle.begin(), cycle.end());
}
void dfs(ll start) { 
    if (res_found) {
        return;
    }
    color[start] = VISITING;
    for (auto to: adj[start]) {
        if (res_found) {
            return;
        }
        if (color[to] == UN_VISITED) {
            parent[to] = start;
            dfs(to);
            continue;
        }
        if (color[to] == VISITING) {
            get_cycle(to, start);
            res_found = true;
            return;
        }
    }
    color[start] = VISITED;
}
 
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
    ll n, m, x, y;
    cin >> n >> m;
	
    adj.resize(n + 1);
    parent.resize(n + 1, 0);
 
	for (ll i = 0; i < m; ++i) {
		cin >> x >> y;
        adj[x].push_back(y);
	}
    for (ll i = 1; i <= n; ++i) {
        if (color[i] == UN_VISITED) {
            dfs(i);
            if (res_found) {
                break;
            }
        }
    }
    if (!res_found) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << cycle.size() << '\n';
    for (auto i: cycle) {
        cout << i << ' ';
    }
}