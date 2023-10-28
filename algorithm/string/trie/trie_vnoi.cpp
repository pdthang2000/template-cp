#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define qq cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;

struct Trie{
    struct Node{
        Node* child[MAX_CHAR];
        int exist, cnt;

        Node() {
            for (int i = 0; i < MAX_CHAR; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };
 
    int string_count;
    Node* root;
    Trie() : string_count(0) {
        root = new Node();
    };
 
    void add_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) p->child[c] = new Node();

            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
        string_count++;
    }

    bool delete_string_recursive(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(p->child[c], s, i + 1);
            if (isChildDeleted) p->child[c] = NULL;
        }
        else p->exist--;

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p); // Khác với cài đặt bằng mảng,
                           // ta có thể thực sự xóa đỉnh này đi
                return true;
            }
        }
        return false;
    }
 
    void delete_string(string s) {
        if (find_string(s) == false) return;
        string_count--;
        delete_string_recursive(root, s, 0);
    }
 
    bool find_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == NULL) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }

    void print_strings() {
        print_strings_recursive(root, ""); 
    }

    void print_strings_recursive(Node* p, string s) {
        if (p->exist > 0) {
            cout << s << endl; 
        }
        
        for (int i = 0; i < MAX_CHAR; i++) {
            if (p->child[i]) {
            print_strings_recursive(p->child[i], s + (char)('a' + i));
            }
        }
    }

    void print_Kth_string(int K) {
        int count = 0;
        print_Kth_util(root, "", K, count);
    }

    void print_Kth_util(Node* p, string s, int K, int& count) {
        if (p->exist > 0) {
            count++;
            if (count == K) {
            cout << s << endl;
            return; 
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (p->child[i]) {
            print_Kth_util(p->child[i], s + (char)('a' + i), K, count); 
            }
        }
    }

    int count_prefix_substr(string x) {
        Node* p = root;
        for (char c : x) {
            int i = c - 'a'; 
            if (p->child[i] == NULL) return 0;
            p = p->child[i];
        }

        return p->cnt; 
    }
    int get_string_count() {
        return this->string_count;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    Trie trie;
  
    // Thêm một số chuỗi
    trie.add_string("hello");
    trie.add_string("helloworld");
    trie.add_string("good");
    trie.add_string("google");
    
    // In ra tất cả các chuỗi theo thứ tự từ điển
    trie.print_strings();
    
    // In ra chuỗi thứ 2 theo thứ tự từ điển 
    trie.print_Kth_string(2);
    
    // Đếm số lần xuất hiện chuỗi "good"
    cout << trie.count_prefix_substr("good") << endl;
    
    // Xóa chuỗi 
    trie.delete_string("good");
    
    // Kiểm tra số chuỗi còn lại
    cout << trie.get_string_count() << endl;

    return 0;
}