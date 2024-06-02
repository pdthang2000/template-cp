#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
vector<int> topological_sort(int len, vector<int> g[]) {
    vector<int> degree(len + 1, 0);
    for (int i = 1; i <= len; ++i) {
        for (auto j: g[i]) {
            degree[j]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= len; ++i) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while (q.size()) {
        int front = q.front();
        q.pop();
        res.push_back(front);
 
        for (auto i: g[front]) {
            degree[i]--;
            if (degree[i] == 0) {
                q.push(i);
            }
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> g[n + 1];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<int> res = topological_sort(n, g);
    if (res.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (auto i: res) {
        cout << i << ' ';
    }
}
/*
Input:

5 3
1 2
3 1
4 5
Output:

3 4 1 5 2
*/