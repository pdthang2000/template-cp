#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
 
const ll INF = INT_MAX;
bool used[200005];
struct Edge {
    ll from, to, cost;
};
 
vector<ll> get_path(ll from, ll to, vector<ll> const &parent) {
    vector<ll> path;
    for (ll cur = to; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}
// 1-based
void bellman_ford_with_negative_cycle(
    ll start, 
    ll n, 
    vector<Edge> const &edges, 
    vector<ll> &parent,
    vector<ll> &distance,
    vector<ll> &cycle
) {
    cycle.clear();
    parent.clear();
    distance.clear();
 
    parent.resize(n + 1, -1);
    distance.resize(n + 1, 0);
 
    distance.resize(n + 1, INF);
    distance[start] = 0;
    ll negative_cycle_check = -1;
 
    for (ll i = 0; i < n; ++i) {
        negative_cycle_check = -1;
        for (Edge e: edges) {
            used[e.to] = true;
            if (distance[e.from] + e.cost < distance[e.to]) {
                distance[e.to] = distance[e.from] + e.cost;
                parent[e.to] = e.from;
                negative_cycle_check = e.to;
            }
        }
    }
    // No negative cycle found
    if (negative_cycle_check == -1) {
        return;
    }
    // Negative cycle found
    ll cycle_start = negative_cycle_check;
    for (ll i = 0; i < n; ++i) {
        // see(cycle_start);seen(parent[cycle_start]);
        cycle_start = parent[cycle_start];
    }
    for (ll cur = cycle_start;; cur = parent[cur]) {
        cycle.push_back(cur);
        if (cur == cycle_start && cycle.size() > 1) {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
}
// 1-based
vector<ll> bellman_ford_with_no_negative_cycle(ll start, ll n, vector<Edge> const &edges, vector<ll> &parent) {
    vector<ll> distance(n + 1, INF);
    distance[start] = 0;
    // for (ll i = 0; i < n - 1; ++i) {}
    for (;;) {
        bool any = false;
        for (Edge e: edges) {
            if (distance[e.from] < INF) {
                if (distance[e.from] + e.cost < distance[e.to]) {
                    distance[e.to] = distance[e.from] + e.cost;
                    any = true;
                    parent[e.to] = e.from;
                }
            }
        }
        if (!any) {
            break;
        }
    }
    return distance;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
    
    vector<ll> parent, distance, cycle;
    
    ll n, m, x, y, z;
    cin >> n >> m;
    vector<Edge> edges;
 
	for (ll i = 0; i < m; ++i) {
		cin >> x >> y >> z;
        Edge edge;
        edge.from = x;
        edge.to = y;
        edge.cost = z;
        edges.push_back(edge);
	}
    // vector<ll> distance = bellman_ford_with_no_negative_cycle(1, n, edges, parent);
    // vector<ll> path = get_path(1, n, parent);
    // for (auto i: path) { cout << i << ' '; } qq;
    // for (ll i = 1; i <= n; ++i) {
    //     if (!used[i]) {
    //         used[i] = 1;
    //         bellman_ford_with_negative_cycle(i, n, edges, parent, distance, cycle);
    //     }
    // }
    bellman_ford_with_negative_cycle(1, n, edges, parent, distance, cycle);
    // for (ll i = 0; i < distance.size(); ++i) { cout << i << ' ' << distance[i] << '\n'; }
    if (cycle.empty()) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (auto i: cycle) {
        cout << i << ' ';
    }
}
/*
Ex: No negative cycle
Input:
5 8
1 2 3
2 3 4
3 4 5
4 5 6
1 3 6
2 4 7
1 4 5
2 5 3
Output:
1 2 5
*/
/*
Ex: With negative cycle
Input:
5 10
1 3 1000
2 4 1000
3 5 1000
4 1 1000
5 2 1000
1 2 -2
2 3 -2
3 4 -2
4 5 -2
5 1 -2
