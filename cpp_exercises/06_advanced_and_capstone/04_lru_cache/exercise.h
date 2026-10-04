#pragma once
#include <unordered_map>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_lru_cache
//    OR:
//    .\run_tests.bat 04_lru_cache
// ============================================================================

// EXERCISE 6.4: LRU Cache (O(1) Hash-Linked Architecture)
// CADT Advanced Algorithm & C++ • Week 5 / System Design
//
// TASKS:
// Build an O(1) Least Recently Used (LRU) Cache:
// 1. Constructor: Validate capacity > 0 (throw invalid_argument if <= 0).
// 2. get(int key):
//    - If key does not exist, return -1.
//    - If key exists, move its node to Most Recently Used (MRU) head and return its value.
// 3. put(int key, int value):
//    - If key exists, update value and move to MRU head.
//    - If key does not exist, insert at MRU head.
//    - If size exceeds capacity, evict the Least Recently Used (LRU) tail node and erase from map.
// 4. Destructor: Safely delete all nodes including dummy head and tail.

class LRUCache {
private:
    struct CacheNode {
        int key{0};
        int value{0};
        CacheNode* prev{nullptr};
        CacheNode* next{nullptr};
        CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity_{0};
    unordered_map<int, CacheNode*> map_;
    CacheNode* head_{nullptr};
    CacheNode* tail_{nullptr};

public:
    explicit LRUCache(int capacity) : capacity_(capacity) {
        // TODO: Validate capacity > 0 (throw invalid_argument if <= 0).
        // Initialize dummy head_ and tail_ sentinels.
        if (capacity <= 0) throw invalid_argument("Capacity must be positive");
        head_ = new CacheNode(0, 0);
        tail_ = new CacheNode(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        // TODO: Free all allocated nodes
        CacheNode* curr = head_;
        while (curr) {
            CacheNode* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;

    int get(int key) {
        // TODO: Lookup key in map_. If not found, return -1.
        // If found, move node to MRU head and return node->value.
        (void)key;
        return -1;
    }

    void put(int key, int value) {
        // TODO: If key exists, update value and move to MRU head.
        // Otherwise, create new node, link at head, add to map.
        // If map.size() > capacity_, evict tail node and erase from map.
        (void)key;
        (void)value;
    }
};
