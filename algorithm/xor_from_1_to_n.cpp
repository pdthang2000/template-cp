#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define see(x) cout<< #x <<" = "<< x <<' ';
#define seen(x) cout<< #x <<" = "<< x <<'\n';
#define UWU cout<<'\n';
ll Q;
ll compute_xor_n(ll n){
    switch(n&3){//n%4
        case 0 : return n;
        case 1 : return 1;
        case 2 : return n + 1;
        case 3 : return 0;
    }
}
void solve(){
    ll n;cin>>n;
    cout<<compute_xor_n(n);
}
int main(){
//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>Q;
    while(Q--){
        solve();
        cout<<'\n';
    }
}
