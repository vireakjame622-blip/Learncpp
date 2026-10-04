#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Singly Linked List
struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SinglyLinkedList() : head_(nullptr), size_(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    void clear() {
        while (head_ != nullptr) {
            SLLNode* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        size_ = 0;
    }

    void pushFront(int val) {
        SLLNode* newNode = new SLLNode(val);
        newNode->next = head_;
        head_ = newNode;
        size_++;
    }

    void pushBack(int val) {
        SLLNode* newNode = new SLLNode(val);
        if (head_ == nullptr) {
            head_ = newNode;
        } else {
            SLLNode* curr = head_;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size_++;
    }

    int popFront() {
        if (empty()) {
            throw runtime_error("List is empty");
        }
        SLLNode* temp = head_;
        int val = temp->data;
        head_ = head_->next;
        delete temp;
        size_--;
        return val;
    }

    bool deleteValue(int val) {
        if (head_ == nullptr) return false;

        // If head matches
        if (head_->data == val) {
            SLLNode* temp = head_;
            head_ = head_->next;
            delete temp;
            size_--;
            return true;
        }

        SLLNode* curr = head_;
        while (curr->next != nullptr && curr->next->data != val) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            SLLNode* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
            size_--;
            return true;
        }
        return false;
    }

    bool contains(int val) const {
        SLLNode* curr = head_;
        while (curr != nullptr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return head_ == nullptr;
    }

    vector<int> toVector() const {
        vector<int> result;
        SLLNode* curr = head_;
        while (curr != nullptr) {
            result.push_back(curr->data);
            curr = curr->next;
        }
        return result;
    }

private:
    SLLNode* head_;
    size_t size_;
};
