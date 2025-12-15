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
class Trie {
public:
    struct Node {
        Node* children[MAX_CHAR];
        ll end_count, prefix_count;
        Node() {
            end_count = prefix_count = 0;
            for (int i = 0; i < MAX_CHAR; i++) children[i] = nullptr;
        }
    };

    ll string_count;
    Node* root;
    Trie() {
        root = new Node();
        string_count = 0;
    }
    
    void insert(string str) {
        Node* node = root;
        for (auto character: str) {
            int c = character - 'a';
            
            if (node->children[c] == nullptr) {
                node->children[c] = new Node();
            }
            node = node->children[c];
            ++node->prefix_count;
        }
        
        ++node->end_count;
        ++string_count;
    }
    
    ll recur_search(string& str, int index, Node* node) {
        if (index == str.size()) {
            return node->end_count;
        }
        char character = str[index];
        int c = character - 'a';
        if (character == WILDCARD) {
            ll total = 0;
            for (int i = 0; i < MAX_CHAR; ++i) {
                if (node->children[i] == nullptr) {
                    continue;
                }

                total += recur_search(str, index + 1, node->children[i]);
            }

            return total;
        }
        if (node->children[c] == nullptr) {
            return 0;
        }
        
        return recur_search(str, index + 1, node->children[c]);
    }

    ll search(string str) {
        Node* node = root;
        return recur_search(str, 0, node);
    }
    
    ll get_prefix_count(string prefix) {
        Node* node = root;
        for (auto character: prefix) {
            int c = character - 'a';
            if (node->children[c] == nullptr) {
                return 0;
            }
            node = node->children[c];
        }
        return node->prefix_count;
    }

    ll get_string_count() {
        return string_count;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    Trie trie;

    // Insert some words
    vector<string> words = {
        "ape",
        "apple",
        "apple",
        "bat",
        "bath",
        "batch",
        "bean",
        "cat",
        "car",
        "dog"
        "orange",
        "orange",
        "orange",
    };

    for (auto &w : words) {
        trie.insert(w);
    }

    cout << "Total strings inserted: " << trie.get_string_count() << "\n\n";

    auto test_search = [&](const string &pattern) {
        ll cnt = trie.search(pattern);
        cout << "search(\"" << pattern << "\") -> " << cnt << "\n";
    };

    test_search("apple");
    test_search("orange");
    test_search("dog");
    test_search("thangfkphan");

    test_search("*pple");
    test_search("ca*");
    test_search("c*t");
    test_search("*at");
    test_search("***");
    test_search("****");

    auto test_prefix = [&](const string &prefix) {
        ll cnt = trie.get_prefix_count(prefix);
        cout << "get_prefix_count(\"" << prefix << "\") -> " << cnt << "\n";
    };

    test_prefix("a");
    test_prefix("ba");
    test_prefix("c");
    test_prefix("app");  
    return 0;
}