#pragma once
#include <unordered_map>
#include <stdexcept>

using namespace std;

// Verified Solution for Exercise 6.2: LRU Cache
class LRUCache {
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode* prev;
        CacheNode* next;
        CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity_;
    unordered_map<int, CacheNode*> map_;
    CacheNode* head_;
    CacheNode* tail_;

    void addNode(CacheNode* node) {
        node->next = head_->next;
        node->prev = head_;
        head_->next->prev = node;
        head_->next = node;
    }

    void removeNode(CacheNode* node) {
        CacheNode* p = node->prev;
        CacheNode* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void moveToHead(CacheNode* node) {
        removeNode(node);
        addNode(node);
    }

    CacheNode* popTail() {
        CacheNode* res = tail_->prev;
        removeNode(res);
        return res;
    }

public:
    explicit LRUCache(int capacity) : capacity_(capacity) {
        if (capacity <= 0) throw invalid_argument("Capacity must be positive");
        head_ = new CacheNode(0, 0);
        tail_ = new CacheNode(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        CacheNode* curr = head_;
        while (curr) {
            CacheNode* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int key) {
        auto it = map_.find(key);
        if (it == map_.end()) return -1;
        CacheNode* node = it->second;
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            CacheNode* node = it->second;
            node->value = value;
            moveToHead(node);
        } else {
            CacheNode* newNode = new CacheNode(key, value);
            map_[key] = newNode;
            addNode(newNode);

            if (static_cast<int>(map_.size()) > capacity_) {
                CacheNode* tail = popTail();
                map_.erase(tail->key);
                delete tail;
            }
        }
    }

    size_t size() const {
        return map_.size();
    }
};
