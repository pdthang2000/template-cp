#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define fi first
#define se second
#define yes cout << "YES";
#define no cout << "NO";
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;

std::vector<ll> calculateZArray(const std::string& str) {
    ll n = str.length();
    std::vector<ll> z(n, 0);
    ll l = 0, r = 0; // Z-box boundaries

    for (ll i = 1; i < n; i++) {
        if (i <= r) {
            // i is within the current Z-box
            z[i] = std::min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            // Update the Z-box boundaries
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

std::vector<ll> findSubstringPositions(const std::string& text, const std::string& pattern) {
    std::string concatenated = pattern + "$" + text;
    std::vector<ll> zArray = calculateZArray(concatenated);
    ll patternLength = pattern.length();
    std::vector<ll> positions;

    for (ll i = patternLength + 1; i < concatenated.length(); i++) {
        if (zArray[i] == patternLength) {
            // A match is found, add the starting position to the positions vector
            positions.push_back(i - patternLength - 1);
        }
    }

    return positions;
}

ll doesSubstringExist(const std::string& text, const std::string& pattern) {
    std::string concatenated = pattern + "$" + text;
    std::vector<ll> zArray = calculateZArray(concatenated);
    int patternLength = pattern.length();

    for (ll i = patternLength + 1; i < concatenated.length(); i++) {
        if (zArray[i] == patternLength) {
            // A match is found
            return i - patternLength - 1;
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s, sub_str;
    getline(cin, s);
    getline(cin, sub_str);
    cout << doesSubstringExist(s, sub_str) << '\n';
    auto p = findSubstringPositions(s, sub_str);
    if (p.size()) {
        for (auto i: p) cout << i << ' ';
    } else {
        cout << "Empty";
    }
}