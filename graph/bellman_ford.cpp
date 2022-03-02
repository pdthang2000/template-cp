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
struct edge {
    ll a, b, cost;
};
 
bool cmp(edge a, edge b) {
    if (a.a < b.a) {
        return 1;
    }
    if (a.a > b.a) {
        return 0;
    }
    return a.b < b.b;
}
 
ll n, m, x, y, w;
 
vector<edge> g;
 
vector<ll> Bellman_Ford() {
    vector<ll> d (n + 1, LLONG_MIN);
    d[1] = 0;
    while (1) {
        bool any = 1;
        for (auto e : g) {
            if (d[e.a] != LLONG_MIN) {
                if (d[e.b] < d[e.a] + e.cost) {
                    d[e.b] = d[e.a] + e.cost;
                    any = 0;
                }
            }
        }
        if (any) break;
    }
    return d;
}
 
void pdthang2000() {
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        g.push_back({x, y, w});
    }
 
    sort(g.begin(), g.end(), cmp);
 
    vector<ll> res = Bellman_Ford();

    cout << (res.back() == LLONG_MIN ? -1 : res.back());
    
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
CURRENT STATUS : TIME LIMIT EXCEEDED
You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.

Your task is to walk from room 1 to room n. What is the maximum score you can get?

Input

The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,…,n.

Then, there are m lines describing the tunnels. Each line has three integers a, b and x: the tunnel starts at room a, ends at room b, and it increases your score by x. All tunnels are one-way tunnels.

You can assume that it is possible to get from room 1 to room n.

Output

Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print −1.

Constraints
1≤2500≤n
1≤5000≤m
1≤a,b≤n
−109≤x≤109
Example

Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Output:
5
*/