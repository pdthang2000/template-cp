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
ll n, q, t, x, y, z, p;
ll a[MAX_N << 1];
struct Node {
    ll val, lazy;
    Node(ll a, ll b) {
        this->val = a;
        this->lazy = b;
    }
    Node() {}
} ST[MAX_N << 3];
 
Node merge(Node a, Node b) {
    return Node(a.val + b.val, 0);
}
 
void update_lazy(ll id) {
    ST[id * 2].lazy += ST[id].lazy;
    ST[id * 2].val += ST[id].lazy;
    
    ST[id * 2 + 1].lazy += ST[id].lazy;
    ST[id * 2 + 1].val += ST[id].lazy;
 
    ST[id].lazy = 0;
}
 
Node build_st_sum(ll pos, ll L, ll R) {
    if (L == R) {
        ST[pos] = Node(a[L], 0);
        return ST[pos];
    }
    ll mid = (L + R) / 2;

    ST[pos] = merge(
        build_st_sum(pos * 2, L, mid),
        build_st_sum(pos * 2 + 1, mid + 1, R)
    );
    return ST[pos];
}
/*
|------||------|
    l-------r
            k
*/
Node update(ll pos, ll L, ll R, ll i_left, ll i_right, ll upd_val) {
    if (i_left > R || i_right < L) {
        return ST[pos];
    }
    if (i_left <= L && R <= i_right) {
        ST[pos].val += upd_val;
        ST[pos].lazy += upd_val;
        return ST[pos]; 
    }
    update_lazy(pos);
    ll mid = (L + R) / 2;
    ST[pos] = merge(
        update(pos * 2, L, mid, i_left, i_right, upd_val),
        update(pos * 2 + 1, mid + 1, R, i_left, i_right, upd_val)
    );
    return ST[pos];
}
Node get(ll pos, ll L, ll R, ll input_index) {
    if (input_index > R || input_index < L) {
        return Node(0, 0);
    }
    if (L == R) {
        return ST[pos];
    }
    update_lazy(pos);
    ll mid = (L + R) / 2;
    return merge(get(pos * 2, L, mid, input_index),
                get(pos * 2 + 1, mid + 1, R, input_index));
}
void pdthang2000() {
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build_st_sum(1, 1, n);

    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        } else {
            cin >> p;
            cout << get(1, 1, n, p).val << '\n';
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