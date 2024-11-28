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

void manacher_odd(string s, vector<int>& palindrome_radius, string &longest_palindrome) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    int start = 0, max_len = 0, max_p = 0;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
        if (p[i] > max_p) {
            max_p = p[i];
            max_len = p[i] * 2 - 1;
            start = i - p[i] + 1;
        }
    }
    longest_palindrome = s.substr(start, max_len);
    palindrome_radius.clear();
    palindrome_radius = vector<int>(begin(p) + 1, end(p) - 1);
    // p = vector<int>(begin(p) + 1, end(p) - 1);
}

string manacher(string s, vector<int>& palindrome_radius, string &longest_palindrome) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    t += '#';
    manacher_odd(t, palindrome_radius, longest_palindrome);
    return t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s = "abcdcbazzzabcdedczz";
    string longest_palindrome = "";
	vector<int> palindrome_radius;
    string new_s = manacher(s, palindrome_radius, longest_palindrome);
    seen(longest_palindrome);
    seen(new_s);
	for (int i = 0; i < palindrome_radius.size(); ++i) {
		cout << new_s[i] << ' ' << palindrome_radius[i] << '\n';
	}
}
