#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool visited[MAXN];
bool isArticulation[MAXN];
int timer;

vector<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
            if (low[to] >= tin[v] && p != -1) {
                isArticulation[v] = true;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        isArticulation[v] = true;
    }
}

void findArticulationPointsAndBridges(int n) {
    timer = 0;
    fill(visited, visited + n, false);
    fill(isArticulation, isArticulation + n, false);
    bridges.clear();

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findArticulationPointsAndBridges(n);

    cout << "Articulation points in the graph:\n";
    for (int i = 0; i < n; ++i) {
        if (isArticulation[i]) {
            cout << i << "\n";
        }
    }

    cout << "Bridges in the graph:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}
/*
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
Articulation points in the graph:
4
5
6
8
10
Bridges in the graph:
8 - 10
5 - 6
4 - 5
*/