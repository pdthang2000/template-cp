#include <iostream>
using namespace std;

struct TrieNode {
  TrieNode *children[26];
  bool isEndOfWord;
  
  TrieNode() {
    isEndOfWord = false;
    for(int i = 0; i < 26; i++)
      children[i] = NULL;
  }
};

// Insert a key into the trie 
void insert(TrieNode* root, string key) {
  TrieNode *pCrawl = root;

  for(int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if(!pCrawl->children[index])
      pCrawl->children[index] = new TrieNode();

    pCrawl = pCrawl->children[index];
  }

  // mark last node as leaf
  pCrawl->isEndOfWord = true;
}

// Search key in the trie
bool search(TrieNode* root, string key) {
  TrieNode *pCrawl = root;

  for(int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if(!pCrawl->children[index])
      return false;

    pCrawl = pCrawl->children[index];
  }

  return (pCrawl != NULL && pCrawl->isEndOfWord);
}  

// Returns true if current node is leaf and contains key
bool isLastNode(TrieNode* root, string key) {
  if (root->isEndOfWord)
    return true;
    
  return false;
}

// Delete key from trie 
void deleteKey(TrieNode* root, string key) {
  if (search(root, key)) {
    TrieNode* pCrawl = root;

    for(int i = 0; i < key.length(); i++) {
      int index = key[i] - 'a';
      if (isLastNode(pCrawl->children[index], key.substr(i+1))) {
        pCrawl->children[index]->isEndOfWord = false;
        return;  
      }
      pCrawl = pCrawl->children[index]; 
    }
  }
}


// Returns true if current node contains key as prefix
bool checkPrefix(TrieNode* root, string key) {
  TrieNode *pCrawl = root;

  for(int i = 0; i < key.length(); i++) {

    int index = key[i] - 'a';
    if(!pCrawl->children[index])
      return false;

    pCrawl = pCrawl->children[index];
  }

  return true;
}

int main() {

  TrieNode *root = new TrieNode();

  insert(root, "apple");
  insert(root, "apps");
  insert(root, "app");

  search(root, "apple") ? cout<<"Yes\n" : cout<<"No\n";
  search(root, "apps") ? cout<<"Yes\n" : cout<<"No\n";
  search(root, "app") ? cout<<"Yes\n" : cout<<"No\n";

  deleteKey(root, "apple");
  search(root, "apple") ? cout<<"Yes\n" : cout<<"No\n";

  checkPrefix(root, "app") ? cout<<"Yes\n" : cout<<"No\n";

  return 0;
}