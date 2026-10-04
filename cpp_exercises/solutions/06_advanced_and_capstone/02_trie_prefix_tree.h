#pragma once
#include <string>
#include <vector>

using namespace std;

// EXERCISE 6.2 REFERENCE SOLUTION: Trie (Prefix Tree)
// CADT Advanced Algorithm & C++

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
    int prefixCount = 0;

    TrieNode() = default;
};

class Trie {
private:
    TrieNode* root;

    void deleteSubtree(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            deleteSubtree(node->children[i]);
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteSubtree(root);
        root = nullptr;
    }

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& word) {
        if (word.empty()) return;
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26) continue;
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->prefixCount++;
        }
        curr->isEndOfWord = true;
    }

    bool search(const string& word) const {
        if (word.empty()) return false;
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26 || !curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr != nullptr && curr->isEndOfWord;
    }

    bool startsWith(const string& prefix) const {
        if (prefix.empty()) return true;
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26 || !curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr != nullptr;
    }

    int countWordsWithPrefix(const string& prefix) const {
        if (prefix.empty()) return 0;
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (idx < 0 || idx >= 26 || !curr->children[idx]) {
                return 0;
            }
            curr = curr->children[idx];
        }
        return curr ? curr->prefixCount : 0;
    }
};
