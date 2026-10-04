#pragma once
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_hash_table_chaining
//    OR:
//    .\run_tests.bat 03_hash_table_chaining
// ============================================================================

// EXERCISE 6.3: Hash Table with Separate Chaining
// CADT Advanced Algorithm & C++ • Week 5 / Hash Tables & Collisions
//
// TASK:
// Build a fixed-capacity Hash Table mapping string keys to int values.
// Resolve bucket collisions using Separate Chaining (singly linked lists).
//
// Requirements:
// 1. HashNode: struct with string key, int value, and HashNode* next.
// 2. Hash function: hashString(key) % bucket_count_.
// 3. insert(key, val): Updates val if key already exists, otherwise prepends new node to bucket.
// 4. get(key): Returns value for key; throws out_of_range("Key not found") if absent.
// 5. contains(key): Returns true if key exists, false otherwise.
// 6. remove(key): Removes key from bucket; returns true if removed, false if not found.
// 7. size() and empty(): Return number of key-value pairs stored.
// 8. loadFactor(): Returns size() / static_cast<double>(bucket_count_).
// 9. Destructor: Safely deallocate all heap nodes to prevent memory leaks!

struct HashNode {
    string key;
    int value{0};
    HashNode* next{nullptr};

    HashNode(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

class StringHashTable {
private:
    size_t bucket_count_;
    size_t size_{0};
    vector<HashNode*> buckets_;

    // Polynomial rolling hash function (djb2)
    size_t hashFunction(const string& key) const {
        size_t hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);
        }
        return hash % bucket_count_;
    }

public:
    explicit StringHashTable(size_t bucket_count = 11)
        : bucket_count_(bucket_count == 0 ? 11 : bucket_count), size_(0), buckets_(bucket_count_, nullptr) {}

    ~StringHashTable() {
        // TODO: Free all allocated nodes across all buckets
    }

    StringHashTable(const StringHashTable&) = delete;
    StringHashTable& operator=(const StringHashTable&) = delete;

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t bucketCount() const {
        return bucket_count_;
    }

    double loadFactor() const {
        return static_cast<double>(size_) / static_cast<double>(bucket_count_);
    }

    void insert(const string& key, int val) {
        // TODO: Compute bucket index = hashFunction(key).
        // Check if key already exists in the chain: if so, update value and return.
        // Otherwise, allocate new HashNode, prepend to bucket chain, increment size_.
    }

    int get(const string& key) const {
        // TODO: Compute bucket index.
        // Traverse chain: if node->key == key, return node->value.
        // If end of chain reached without match, throw out_of_range("Key not found").
        throw out_of_range("Key not found");
    }

    bool contains(const string& key) const {
        // TODO: Return true if key exists in table, false otherwise.
        return false;
    }

    bool remove(const string& key) {
        // TODO: Compute bucket index.
        // Search chain for key, tracking prev and curr pointers.
        // If found, unlink node, delete node, decrement size_, and return true.
        // If not found, return false.
        return false;
    }
};
