#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll q, n;
ll Hash[MAX_N * 10], p[MAX_N * 10];

void hashing(string s) {
    Hash[0] = s[0];
    p[0] = 1;

    for (ll i = 1; i < n; ++i) {
        Hash[i] = Hash[i - 1] * H + s[i];
        Hash[i] %= MOD;
        p[i] = p[i - 1] * H; 
        p[i] %= MOD;
    }
}
ll cal_hash(string s) {
    ll res = s[0];

    for (ll i = 1; i < s.size(); ++i) {
        res = res * H + s[i];
        res %= MOD;
    }
    return res;
}
ll get_hash(ll x, ll y) {
    if (x == 0) return Hash[y];
    return ((Hash[y] + MOD) - (Hash[x - 1] * p[y - x + 1]) % MOD) % MOD;
}
void pdthang2000() {
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size()) {
        cout << 0;
        return;
    }
    n = s.size();

    hashing(s);

    ll hash_t = cal_hash(t);
    ll cnt = 0;

    for (ll i = 0; i < n - t.size() + 1; ++i) {
        if (get_hash(i, i + t.size() - 1) == hash_t) {
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (MULTI_TESTS) {
        ll Q;
        cin >> Q;
        while (Q--) {
            pdthang2000();
            endl;
        }
    } else {
        pdthang2000();
    }
}