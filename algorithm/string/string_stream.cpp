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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s = "192.168.1.1";
    stringstream s_str_stream(s);
    string segment;
    while (getline(s_str_stream, segment, '.')) {
        cout << segment << '\n';
    }
}