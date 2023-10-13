/**
created by Son Dinh
this program will calculate sum first n fibonaci number(modulo 1e9 + 7) with timecomplexity O(logn)
formula: f[0] + f[1] + f[2] + ... + f[n] = f[n+2] - 1, you can see the proof of this on wikipedia
use matrix to calculate the n-th fibonaci number with imecomplexity O(logn)
|0 1| * |x| = |y    |
|1 1|   |y|   |x + y|
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int n;

struct matrix {
    long long val[2][2];
    matrix(int x, int y, int z, int t) {
        val[0][0] = x;
        val[0][1] = y;
        val[1][0] = z;
        val[1][1] = t;
    }
};
matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(0, 0, 0, 0);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) 
        for (int k = 0; k < 2; ++k)
            ret.val[i][j] = (ret.val[i][j] + (a.val[i][k] * b.val[k][j]) % mod) % mod;
    return ret;
}
matrix fpow(matrix a, int b) {
    matrix ans = matrix(1, 0, 0, 1);
    while(b) {
        if (b&1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
ll fib(ll n) {
    matrix ans = matrix(0,1,1,1);
    return (fpow(ans,n).val[0][1]-1+mod)%mod + 1;
}

ll pre(ll n) {
    matrix ans = matrix(0,1,1,1);
    return (fpow(ans,n+2).val[0][1]-1+mod)%mod + 1;   
}

void solve() {
    cin >> n;
    matrix ans = matrix(0,1,1,1);
    cout << (fpow(ans,n).val[0][1]-1+mod)%mod + 1 << ' ';
    cout << (fpow(ans,n+2).val[0][1]-1+mod)%mod + 1<< '\n';

    ll x = 1, y = 1;
    cout << x << ' ';
    ll sum = 2;
    for (ll i = 3; i <= n; ++i) {
        ll z = x + y;
        x = y;
        y = z;
        cout << z << ' ';
        sum += z;
    }
    cout << "sum = " << sum << endl;
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}
