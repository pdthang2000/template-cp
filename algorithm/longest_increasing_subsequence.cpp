#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

struct compare_first {
    bool operator()(const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) const {
        return lhs.first < rhs.first;
    }
};
// O (nlog(n))
void get_length_with_trace(vector<ll> nums) {
	ll n = nums.size();
	vector<pair<ll,ll>> subsequence;
	map<pair<ll, ll>, pair<ll, ll>> mp;

	subsequence.push_back({nums[0], 0});
	mp[{nums[0], 0}] = {-1, -1};

	for (ll i = 1; i < n; ++i) {
		ll t = nums[i];
		pair<ll, ll> p = {t, i};
		auto it = lower_bound(subsequence.begin(), subsequence.end(), p, compare_first());
		auto clone_it = it;

		if (it == subsequence.begin()) {
			mp[{t, i}] = {-1, -1};
		} else {
			mp[{t, i}] = *--clone_it;
		}

		if (it == subsequence.end()) {
			subsequence.push_back({t, i});
		} else {
			*it = p;
		}
		// for (auto j : subsequence) { cout << j.fi << ',' << j.se << ' '; } qq;
		// for (auto j : mp) { cout << "{" << j.fi.fi << "," << j.fi.se << "} = {" << j.se.fi << "," << j.se.se << "}\n"; }
	}
	auto p = subsequence.back();
	vector<ll> trace;

	while (1) {
		trace.push_back(p.fi);
		if (mp[p].fi == -1) {
			break;
		}
		p = mp[p];
	}

	trace.resize(unique(trace.begin(), trace.end()) - trace.begin());

	cout << trace.size() << '\n';
	for (ll i = trace.size() - 1; i >= 0; --i) {
		cout << trace[i] << ' ';
	}
}
// O (nlog(n))
ll get_length_of_LIS(vector<ll> nums) {
	ll n = nums.size();
	vector<ll> subsequence;

	subsequence.push_back(nums[0]);

	for (ll i = 1; i < n; ++i) {
		ll t = nums[i];
		auto it = lower_bound(subsequence.begin(), subsequence.end(), t);

		if (it == subsequence.end()) {
			subsequence.push_back(t);
		} else {
			*it = t;
		}
	}
	return subsequence.size();
}
// O(n^2)
void dp_version(vector<ll> nums) {
	ll a[3000], dp[3000], trace[3000], x[3000], m = 0, pos = 0, p = 1;
	ll n = nums.size();
	dp[1] = 1;

    for(ll i = 1; i <= n; ++i) {
		a[i] = nums[i - 1];
        dp[i] = 1;
        for(ll j = 1 ; j < i ; ++j) {
            if (a[i] > a[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
        m = max(m, dp[i]);
    }

    for (ll i = 1; i <= n; ++i) {
        if(dp[i] == m) pos = i;
    }
    
    while (p <= m) {
        x[p] = a[pos];
        pos = trace[pos];
        p++;
    }

    cout << m << '\n';
	for (ll i = m; i >= 1; --i) {
        cout << x[i] << ' ';
    }
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (auto &i: v) cin >> i;
	dp_version(v);
	// get_length_of_LIS(v);
	// get_length_with_trace(v);
}