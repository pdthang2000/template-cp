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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
	vector<int> all_palindrome_center;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] != '#') {
			all_palindrome_center.push_back(res[i] - 1);
		}
	}

    return all_palindrome_center;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s = "abcdcbazzzabcdedczz";
	vector<int> all_palindrome_center = manacher(s);
	for (int i = 0; i < all_palindrome_center.size(); ++i) {
		cout << s[i] << ' ' << all_palindrome_center[i] << '\n';
	}
}
