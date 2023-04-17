#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
ll d, g; // x,y : global variables
ll extendedEuclid(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        d = a;
        *x = 1;
        *y = 0;
        return a;
    }
    else {
        ll x1,y1;
        ll z = extendedEuclid(b, a%b, &x1, &y1);
        *x = y1;
        *y = x1 - (a / b) * y1;
        return z;
    }
}

ll modulo_inverse_euclidean(ll n, ll m) {
  ll x1, y1;
  if (extendedEuclid(n, m, &x1, &y1) != 1) return -1; // not exist
  return (x1 % m  + m) % m; // vì x có thể âm
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll num1, num2, x, y;
    cin >> num1 >> num2;
    ll m = num2;
    g = extendedEuclid(num1, num2, &x, &y);
    cout << "gcd(num1, num2) = " << d << endl;
    cout << "x, y: " << x <<  ", " << y << endl; //num1 * x + num2 * y = 1
    cout<<modulo_inverse_euclidean(num1, m);
    return 0;
}

