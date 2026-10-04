#pragma once
#include <string>
#include <memory>
#include <vector>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 02_trie_prefix_tree
//    OR:
//    .\run_tests.bat 02_trie_prefix_tree
// ============================================================================

// EXERCISE 6.2: Trie (Prefix Tree & Autocomplete Engine)
// CADT Advanced Algorithm & C++ • Week 5 / Trees & Prefix Structures
//
// TASK:
// Implement a Prefix Tree (Trie) for lowercase English words ('a' through 'z').
//
// Core Operations to Implement:
// 1. insert(const string& word): Adds word into the Trie.
// 2. search(const string& word) const: Returns true if exact word is present.
// 3. startsWith(const string& prefix) const: Returns true if any word begins with prefix.
// 4. countWordsWithPrefix(const string& prefix) const: Counts words with given prefix.
// 5. Destructor / Memory cleanup: ensure 0 memory leaks!

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
    int prefixCount = 0; // Number of words passing through this node

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

    int countSubtreeWords(TrieNode* node) const {
        if (!node) return 0;
        int count = node->isEndOfWord ? 1 : 0;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                count += countSubtreeWords(node->children[i]);
            }
        }
        return count;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteSubtree(root);
        root = nullptr;
    }

    // Disable copy for simplicity in pointer management
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& word) {
        // TODO: Insert characters into Trie, updating prefixCount and setting isEndOfWord
    }

    bool search(const string& word) const {
        // TODO: Return true if exact word exists and is marked as isEndOfWord
        return false;
    }

    bool startsWith(const string& prefix) const {
        // TODO: Return true if any path matches prefix
        return false;
    }

    int countWordsWithPrefix(const string& prefix) const {
        // TODO: Return count of words starting with prefix
        return 0;
    }
};
