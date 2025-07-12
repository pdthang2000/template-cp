// #include <bits/stdc++.h>
#include "stdc++.h"
#define ll long long
using namespace std;
#define qq cout << '\n';
// Fenwick (BIT) supporting point updates & prefix sums
struct FenwickTree {
    ll n;
    vector<int> bit;
    FenwickTree(ll _n): n(_n), bit(n + 1, 0) {}

    // add v at index i
    void update(ll i, ll v) {
        while (i <= n) {
            bit[i] += v;
            i += i & (-i);
        }
        // for (; i <= n; i += i&-i) bit[i] += v;
    }
    // sum of [1..i]
    ll query(ll i) const {
        ll sum = 0;
        while (i) {
            sum += bit[i];
            i -= i & (-i);
        }
        // for (; i > 0; i -= i&-i) s += bit[i];
        return sum;
    }
    // In other contexts it’s referred to as:
    //   “BIT lower_bound on prefix sums”
    //   “Order‐statistics with a Fenwick tree”
    //   “Binary lifting on a binary indexed tree”
    // find smallest id such that query(id) >= k
    ll findByOrder(ll k) const {
        ll id = 0;
        // highest power of two ≤ n:
        ll mask = 1LL << (63 - __builtin_clzll(n));
        // ll mask = 1;
        // while ((mask << 1) <= n) {
        //     mask <<= 1;
        // }
        for (; mask; mask >>= 1) {
            ll next = id + mask;
            if (next <= n && bit[next] < k) {
                id = next;
                k  = k - bit[next];
            }
        }
        return id + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    FenwickTree fw(10);
    for (int i = 1; i <= 10; ++i) {
        if (i & 1) {
            fw.update(i, 1);
        } 
    }
    for (int i = 1; i <= 10; ++i) {
        cout << fw.query(i) << ' ';
    } qq;

    for (int i = 1; i <= 5; ++i) {
        cout << fw.findByOrder(i) << ' ';
    }
}