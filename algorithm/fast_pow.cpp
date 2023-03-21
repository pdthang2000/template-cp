#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll fast_pow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
ll fast_pow_with_mod(ll a, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * a) % p;
        a = (a * a) % p;
        n >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll a, n, p;
    cin >> a >> n >> p;
    cout << fast_pow(a, n) << '\n';
    cout << fast_pow_with_mod(a, n, p) << '\n';
}