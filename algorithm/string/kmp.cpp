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
const ll MAX_CHAR = 26;
const char WILDCARD = '*';

// Build LPS (Longest Prefix Suffix) array
vector<int> build_lps(const string& p) {
    int m = p.size();
    vector<int> lps(m, 0);
    // len: “How many characters of prefix are currently matched”
    int len = 0;
    for (int i = 1; i < m; ) {
        if (p[i] == p[len]) {
            //++len;
            //lps[i] = len;
            //++i;
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

// Return all starting positions where p appears in s
vector<int> kmp(const string& s, const string& p) {
    vector<int> res;
    if (p.empty()) return res;

    vector<int> lps = build_lps(p);
    // qq; for (auto i: lps) { cout << i << ' '; } qq;
    for (int i = 0, j = 0; i < (int)s.size(); ) {
        if (s[i] == p[j]) {
            i++; j++;
            if (j == (int)p.size()) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j > 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return res;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    // Example to test lps 
    {
        string temp = "AAACAAAAAC";
        auto pos = build_lps(temp);
        for (auto i: temp) { cout << i << ' '; } qq;
        for (auto i: pos) { cout << i << ' '; } qq;
    }
    // Example 1: Basic search
    {
        string text = "ababa";
        string pattern = "aba";

        auto pos = kmp(text, pattern);

        cout << "Example 1\n";
        cout << "Text: " << text << "\n";
        cout << "Pattern: " << pattern << "\n";
        cout << "Positions: ";
        for (int x : pos) cout << x << " ";
        cout << "\n\n";
        // Expected: 0 2
    }

    // Example 2: Overlapping matches
    {
        string text = "aaaaa";
        string pattern = "aaa";

        auto pos = kmp(text, pattern);

        cout << "Example 2 (overlapping)\n";
        cout << "Text: " << text << "\n";
        cout << "Pattern: " << pattern << "\n";
        cout << "Positions: ";
        for (int x : pos) cout << x << " ";
        cout << "\n\n";
        // Expected: 0 1 2
    }

    // Example 3: Pattern not found
    {
        string text = "abcdef";
        string pattern = "gh";

        auto pos = kmp(text, pattern);

        cout << "Example 3 (not found)\n";
        cout << "Text: " << text << "\n";
        cout << "Pattern: " << pattern << "\n";
        cout << "Positions: ";
        if (pos.empty()) cout << "none";
        cout << "\n\n";
    }

    // Example 4: Long classical KMP test
    {
        string text = "ABABDABACDABABCABAB";
        string pattern = "ABABCABAB";

        auto pos = kmp(text, pattern);

        cout << "Example 4 (classic KMP)\n";
        cout << "Text: " << text << "\n";
        cout << "Pattern: " << pattern << "\n";
        cout << "Positions: ";
        for (int x : pos) cout << x << " ";
        cout << "\n\n";
        // Expected: 10
    }
    return 0;
}


/*

We keep the same comprehensive example:

p = "AAACAAAAAC"
idx = 0..9

Clean, aligned regeneration (every step)
State 0 (start)

i=1, len=0

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:  ^                           
i:       ^                        
lps:  0  0  0  0  0  0  0  0  0  0


Compare p[1]=A vs p[0]=A ✅ → set lps[1]=1, now i=2,len=1

State 1

i=2, len=1

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:     ^                        
i:          ^                     
lps:  0  1  0  0  0  0  0  0  0  0


Compare p[2]=A vs p[1]=A ✅ → set lps[2]=2, now i=3,len=2

State 2

i=3, len=2

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:        ^                     
i:             ^                  
lps:  0  1  2  0  0  0  0  0  0  0


Compare p[3]=C vs p[2]=A ❌ → fallback len=lps[1]=1 (i stays 3)

State 3 (after fallback 1)

i=3, len=1

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:     ^                        
i:             ^                  
lps:  0  1  2  0  0  0  0  0  0  0


Compare p[3]=C vs p[1]=A ❌ → fallback len=lps[0]=0 (i stays 3)

State 4 (after fallback 2)

i=3, len=0

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:  ^                           
i:             ^                  
lps:  0  1  2  0  0  0  0  0  0  0


Compare p[3]=C vs p[0]=A ❌ and len==0 → set lps[3]=0, now i=4,len=0

State 5

i=4, len=0

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:  ^                           
i:                ^               
lps:  0  1  2  0  0  0  0  0  0  0


Compare p[4]=A vs p[0]=A ✅ → set lps[4]=1, now i=5,len=1

State 6 ✅ (this is the one you called out)

i=5, len=1

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:     ^                        
i:                   ^            
lps:  0  1  2  0  1  0  0  0  0  0


Compare p[5]=A vs p[1]=A ✅ → set lps[5]=2, now i=6,len=2

State 7

i=6, len=2

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:        ^                     
i:                      ^         
lps:  0  1  2  0  1  2  0  0  0  0


Compare p[6]=A vs p[2]=A ✅ → set lps[6]=3, now i=7,len=3

State 8

i=7, len=3

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:           ^                  
i:                         ^      
lps:  0  1  2  0  1  2  3  0  0  0


Compare p[7]=A vs p[3]=C ❌ → fallback len=lps[2]=2 (i stays 7)

State 9 (after fallback)

i=7, len=2

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:        ^                     
i:                         ^      
lps:  0  1  2  0  1  2  3  0  0  0


Retry: p[7]=A vs p[2]=A ✅ → set lps[7]=3, now i=8,len=3

State 10

i=8, len=3

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:           ^                  
i:                            ^   
lps:  0  1  2  0  1  2  3  3  0  0


Compare p[8]=A vs p[3]=C ❌ → fallback len=lps[2]=2 (i stays 8)

State 11 (after fallback)

i=8, len=2

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:        ^                     
i:                            ^   
lps:  0  1  2  0  1  2  3  3  0  0


Retry: p[8]=A vs p[2]=A ✅ → set lps[8]=3, now i=9,len=3

State 12

i=9, len=3

idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
len:           ^                  
i:                               ^
lps:  0  1  2  0  1  2  3  3  3  0


Compare p[9]=C vs p[3]=C ✅ → set lps[9]=4, done.

Final (aligned)
idx:  0  1  2  3  4  5  6  7  8  9
p:    A  A  A  C  A  A  A  A  A  C
lps:  0  1  2  0  1  2  3  3  3  4


*/