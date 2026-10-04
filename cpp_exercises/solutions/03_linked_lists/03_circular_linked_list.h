#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Circular Linked List & Josephus Problem
struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedList() : head_(nullptr), size_(0) {}

    ~CircularLinkedList() {
        clear();
    }

    void clear() {
        if (head_ == nullptr) return;
        CLLNode* curr = head_->next;
        while (curr != head_) {
            CLLNode* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        delete head_;
        head_ = nullptr;
        size_ = 0;
    }

    void pushBack(int val) {
        CLLNode* newNode = new CLLNode(val);
        if (head_ == nullptr) {
            head_ = newNode;
            head_->next = head_; // points to itself
        } else {
            CLLNode* curr = head_;
            while (curr->next != head_) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head_;
        }
        size_++;
    }

    bool empty() const {
        return head_ == nullptr;
    }

    size_t size() const {
        return size_;
    }

    vector<int> toVector() const {
        vector<int> res;
        if (head_ == nullptr) return res;
        CLLNode* curr = head_;
        do {
            res.push_back(curr->data);
            curr = curr->next;
        } while (curr != head_);
        return res;
    }

    int josephusEliminate(int step) {
        if (empty() || step <= 0) throw invalid_argument("Invalid list or step");

        CLLNode* curr = head_;
        CLLNode* prev = nullptr;

        // Find the predecessor of head_
        while (curr->next != head_) {
            curr = curr->next;
        }
        prev = curr;
        curr = head_;

        while (size_ > 1) {
            // Count step - 1 times
            for (int count = 1; count < step; ++count) {
                prev = curr;
                curr = curr->next;
            }

            // Remove curr
            prev->next = curr->next;
            if (curr == head_) {
                head_ = curr->next;
            }
            delete curr;
            size_--;
            curr = prev->next;
        }

        head_ = curr;
        return head_->data;
    }

private:
    CLLNode* head_;
    size_t size_;
};
