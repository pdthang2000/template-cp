#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cerr << #x << " = " << x << ' ';
#define seen(x) cerr << #x << " = " << x << '\n';
#define qq cerr << '\n';
const ll MAX_N = 200'005;
const ll MOD = 1'000'000'007;
ll n, m, x, y;

vector<vector<ll>> adj(MAX_N);

vector<bool> visited(MAX_N);
vector<ll> time_in(MAX_N), lowest_time(MAX_N);
map<ll, bool> is_cutpoint;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    time_in[v] = lowest_time[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;

        if (visited[to]) {
            lowest_time[v] = min(lowest_time[v], time_in[to]);
        } else {
            dfs(to, v);
            lowest_time[v] = min(lowest_time[v], lowest_time[to]);
            if (lowest_time[to] >= time_in[v] && p != -1) {
                is_cutpoint[v] = true;   
            }
            ++children;
        }
    }
    if(p == -1 && children > 1)
        is_cutpoint[v] = true;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    time_in.assign(n, -1);
    lowest_time.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_cutpoints();
    for (auto i: is_cutpoint) {
        cout << i.first << ' ';
    }
}

/* Ex1
Input:
12 14
1 2
2 3
3 4
4 1
4 5
5 6
6 7
7 8
8 9
9 6
8 10
10 11
11 12
12 10

Output:
8 10
5 6
4 5
*/