#pragma once
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// EXERCISE 6.3 REFERENCE SOLUTION: Hash Table with Separate Chaining
// CADT Advanced Algorithm & C++

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
        for (size_t i = 0; i < bucket_count_; ++i) {
            HashNode* curr = buckets_[i];
            while (curr) {
                HashNode* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
            buckets_[i] = nullptr;
        }
        size_ = 0;
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
        size_t idx = hashFunction(key);
        HashNode* curr = buckets_[idx];
        while (curr) {
            if (curr->key == key) {
                curr->value = val;
                return;
            }
            curr = curr->next;
        }

        HashNode* newNode = new HashNode(key, val);
        newNode->next = buckets_[idx];
        buckets_[idx] = newNode;
        ++size_;
    }

    int get(const string& key) const {
        size_t idx = hashFunction(key);
        HashNode* curr = buckets_[idx];
        while (curr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        throw out_of_range("Key not found");
    }

    bool contains(const string& key) const {
        size_t idx = hashFunction(key);
        HashNode* curr = buckets_[idx];
        while (curr) {
            if (curr->key == key) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool remove(const string& key) {
        size_t idx = hashFunction(key);
        HashNode* curr = buckets_[idx];
        HashNode* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    buckets_[idx] = curr->next;
                }
                delete curr;
                --size_;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
};
