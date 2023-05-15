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
ll n, x, y, z, t, q;
ll a[MAX_N << 1];
struct node {
    ll l_sum, r_sum, sum, max_sum;
    node(ll a, ll b, ll c, ll d) {
        this->l_sum = max(0LL, a);
        this->r_sum = max(0LL, b);
        this->sum = c;
        this->max_sum = max(0LL, d);
    }
    node() {}
} st[MAX_N << 3];
 
node merge(node a, node b) {
    x = max(0LL, max(a.l_sum, a.sum + b.l_sum));
    y = max(0LL, max(b.r_sum, a.r_sum + b.sum));
    z = a.sum + b.sum;
    return node(
        x,
        y,
        z,
        max((0LL, a.r_sum + b.l_sum), max(a.max_sum, b.max_sum))  
    );
}
 
void update(ll pos, ll L, ll R, ll id, ll val) {
    if (L == R) {
        st[pos] = node(a[L], a[R], a[L], a[R]);
        return;
    }
    ll mid = (L + R) >> 1;
    if (id <= mid) {
        update(pos << 1, L, mid, id, val);
    } else {
        update(pos << 1 | 1, mid + 1, R, id , val);
    }
 
    st[pos] = merge(st[pos << 1], st[pos << 1 | 1]);
}
 
void build(ll pos, ll L, ll R) {
    if (L == R) {
        st[pos] = node(a[L], a[R], a[L], a[R]);
        return;
    }
    ll mid = (L + R) >> 1;
    build(pos << 1, L, mid);
    build(pos << 1 | 1, mid + 1, R);
    st[pos] = merge(st[pos << 1], st[pos << 1 | 1]);
}
 
void show() { return;
    for (ll i = 1; i <= 12; ++i) {
        cout << st[i].l_sum << ' ' << st[i].r_sum << ' ' << st[i].sum << ' ' << st[i].max_sum << '\n';
    } qq;
}
 
void pdthang2000() {
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    show();
    while (q--) {
        cin >> x >> y;
        a[x] = y;
        update(1, 1, n, x, y);
        show();
        cout << st[1].max_sum << '\n';
    }
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