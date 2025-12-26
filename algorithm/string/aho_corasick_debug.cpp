#include "stdc++.h"
using namespace std;

#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define ll long long

const ll MAX_CHAR = 26;

class AhoCorasick {
public:
    struct Node {
        Node* children[MAX_CHAR];
        Node* link;      // failure link
        Node* out;       // next terminal node in fail chain
        Node* parent;    // parent in trie (for debugging)
        char ch;         // character from parent -> this node
        vector<int> ids; // pattern ids ending here

        Node(char _ch = '#', Node* _parent = nullptr) {
            for (int i = 0; i < MAX_CHAR; i++) children[i] = nullptr;
            link = nullptr;
            out = nullptr;
            parent = _parent;
            ch = _ch;
        }
    };

    Node* root;
    vector<string> patterns;

    AhoCorasick() {
        root = new Node('#', nullptr);
        root->link = root;
        root->out = nullptr;
    }

    // Insert pattern
    void insert(const string& s) {
        int id = (int)patterns.size();
        patterns.push_back(s);

        Node* node = root;
        for (char ch : s) {
            int c = ch - 'a';
            if (!node->children[c]) {
                node->children[c] = new Node(ch, node);
            }
            node = node->children[c];
        }
        node->ids.push_back(id);
    }

    // Build failure + output links
    void build() {
        queue<Node*> q;
        
        // Depth 1
        cout << "Depth 1\n";
        for (int c = 0; c < MAX_CHAR; c++) {
            Node* nxt = root->children[c];
            if (nxt) {
                char ch = (char)(c + 'a'); seen(ch);
                nxt->link = root;
                nxt->out = root->ids.empty() ? nullptr : root;
                q.push(nxt);
            }
        }

        // BFS
        cout << "Deeper\n";
        while (!q.empty()) {
            Node* v = q.front(); q.pop();
            cout << "\nNew Q:\n";
            seen(v->parent->ch);seen(v->ch);
            for (int c = 0; c < MAX_CHAR; c++) {
                Node* u = v->children[c];
                if (!u) continue;

                Node* f = v->link;
                cout << "\nNew c: "<< (char)(c + 'a') << "\n";
                seen(u->ch);
                seen(f->ch);
                cout << "Before\n";
                while (f != root && !f->children[c]) {
                    f = f->link;
                    cout << "Looped: ";see(f->ch);
                }
                seen(f->ch);
                cout << "After\n";
                if (f->children[c] && f->children[c] != u) {
                    f = f->children[c];
                }
                seen(f->ch);
                u->link = f;

                // output link
                if (!u->link->ids.empty()) u->out = u->link;
                else u->out = u->link->out;

                q.push(u);
            }
        }
    }

    // Step transition (KMP-style fallback)
    Node* step(Node* state, int c) {
        while (state != root && !state->children[c]) {
            state = state->link;
        }
        if (state->children[c]) state = state->children[c];
        return state;
    }

    // Find all matches (endIndex, patternId)
    vector<pair<int,int>> find_all(const string& text) {
        vector<pair<int,int>> matches;
        Node* state = root;

        for (int i = 0; i < (int)text.size(); i++) {
            int c = text[i] - 'a';
            state = step(state, c);

            for (int id : state->ids)
                matches.push_back({i, id});

            for (Node* x = state->out; x != nullptr; x = x->out) {
                for (int id : x->ids)
                    matches.push_back({i, id});
            }
        }
        return matches;
    }

    // Helper: reconstruct string represented by a node
    string node_string(Node* u) {
        string s;
        while (u && u->parent) {
            s.push_back(u->ch);
            u = u->parent;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    // Debug: print fail + out links
    void debug_links() {
        cout << "\n=== FAILURE / OUTPUT LINKS ===\n";
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* u = q.front(); q.pop();
            for (int c = 0; c < MAX_CHAR; c++)
                if (u->children[c]) q.push(u->children[c]);

            if (u == root) continue;

            cout << "node = \"" << node_string(u) << "\""
                 << " | fail = \"" << node_string(u->link) << "\"";

            if (u->out)
                cout << " | out = \"" << node_string(u->out) << "\"";
            else
                cout << " | out = null";

            if (!u->ids.empty())
                cout << " | TERMINAL";

            cout << '\n';
        }
        cout << "==============================\n\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    int q;
    cin >> q;
    AhoCorasick ac;
    while (q--) {
        string pattern;
        cin >> pattern;
        ac.insert(pattern);
    }

    ac.build();
    ac.debug_links();

    auto matches = ac.find_all(text);

    cout << "=== MATCHES ===\n";
    for (auto [endIdx, id] : matches) {
        const string& p = ac.patterns[id];
        int start = endIdx - (int)p.size() + 1;
        cout << "match: \"" << p << "\" at [" << start << ", " << endIdx << "]\n";
    }
}

/*
clamplentyy
4
ample
lamp
plenty
typhoon

aabcde
5
abcd
abcde
bcd
cd
d
Loop runs multiple times
*/
