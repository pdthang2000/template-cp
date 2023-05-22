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
ll n, q, x, y, z;
ll a[MAX_N<<1], ST[MAX_N<<3];

ll merge(ll left_node, ll right_node) {
    return left_node + right_node;
}

ll build_st_sum(ll pos, ll L, ll R) {
    if (L == R) {
        ST[pos] = a[L];
        return a[L];
    }
    ll mid = (L + R) / 2;
    ST[pos] = merge(
        build_st_sum(pos * 2, L, mid),
        build_st_sum(pos * 2 + 1, mid + 1, R)
    );
    return ST[pos];
}

ll update(ll pos, ll L, ll R, ll upd_pos, ll upd_val) {
    if (upd_pos > R || upd_pos < L) {
        return ST[pos];
    }
    if (L == R) {
        a[L] = upd_val;
        ST[pos] = upd_val;
        return ST[pos]; 
    }
    ll mid = (L + R) / 2;
    ST[pos] = merge(
        update(pos * 2, L, mid, upd_pos, upd_val), 
        update(pos * 2 + 1, mid + 1, R, upd_pos, upd_val)
    );
    return ST[pos];
}
ll get(ll pos, ll L, ll R, ll i_left, ll i_right) {
    if (L > i_right || R < i_left) {
        return 0;
    }
    if (i_left <= L && R <= i_right) {
        return ST[pos];
    }
    ll mid = (L + R) / 2;
    return merge(
        get(pos * 2, L, mid, i_left, i_right), 
        get(pos * 2 + 1, mid + 1, R, i_left, i_right)
    );
}
void pdthang2000() {
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build_st_sum(1, 1, n);

    while (q--) {
        cin >> z >> x >> y;
        if (z == 1) {
            update(1, 1, n, x, y);
        } else {
            cout << get(1, 1, n, x, y) << '\n';
        }
    }
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