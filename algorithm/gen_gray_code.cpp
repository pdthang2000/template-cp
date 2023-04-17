#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
#define fi first
#define se second
const ll MAX_N = 100100;
ll n;
int main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<string> a;
    cin >> n;
    if (n == 1) {
        cout << "0\n1";
        return 0;
    }
    a.pb("0");
    a.pb("1");
    for (ll i = 2 ; i <= n ; ++i) {
        ll sz = a.size();
        for (ll j = a.size() - 1 ; j >= 0 ; --j) {
//            see(j);
            a.pb(a[j]);
        }
        for (ll  j = 0 ; j < a.size() / 2 ; ++j) {
            a[j] = '0' + a[j];
        }
        for (ll  j = a.size() / 2 ; j < a.size() ; ++j) {
            a[j] = '1' + a[j];
        }
//        for (auto i : a) cout << i << ' ';UWU;
    }
    for (auto i : a) cout << i << '\n';
}
//cout.precision(18);
//cout << fixed;

