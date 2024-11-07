// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define cer(x) cerr << #x << " = " << x << ' ';
#define cern(x) cerr << #x << " = " << x << '\n';
#define cc cerr << '\n';
const bool MULTIPLE_QUERY = 0;
const ll MAX_N = 200'005;
const ll MOD = 1e9 + 7;

vector<ll> get_Pascal_row(ll n) {
    ll comb_value = 1;
	vector<ll> row;
	row.push_back(comb_value);
    for (int k = 0; k < n; ++k) {
        comb_value = comb_value * (n - k) / (k + 1);
		row.push_back(comb_value);
    }
    return row;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
    cin >> n;
    vector<ll> res = get_Pascal_row(n);
	for (auto i: res) { cout << i << ' ';};
}