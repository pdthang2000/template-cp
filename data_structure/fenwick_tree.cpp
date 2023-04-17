#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX_N = 200100;
ll n, q, t;
ll fw[MAX_N];

void update(ll pos, ll val) {
    while (pos <= MAX_N) {
        fw[pos] += val;
        pos += (pos & -pos);
    }
}

ll get(ll pos) {
    ll sum = 0;
    while (pos) {
        sum += fw[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    update(1, 1);
    update(5, 3);
    update(7, -2);
    for (ll i = 1; i < 10; ++i) {
        cout << get(i) << ' ';
    }
}