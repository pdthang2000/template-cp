#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}
int main() {
//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;cin >> n;
    cout << phi(n);
    /*
    The Euler's Totient Function counts the numbers lesser than a number say n that
    do not share any common positive factor other than 1 with n or
    in other words are co-prime with n.
    Vietnamese version : đếm số lượng số nguyên tố cùng nhau của n.
    */
}

