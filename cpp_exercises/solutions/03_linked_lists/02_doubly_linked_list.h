#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// SOLUTION: Doubly Linked List
struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head_ != nullptr) {
            DLLNode* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        tail_ = nullptr;
        size_ = 0;
    }

    void pushFront(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (head_ == nullptr) {
            head_ = tail_ = newNode;
        } else {
            newNode->next = head_;
            head_->prev = newNode;
            head_ = newNode;
        }
        size_++;
    }

    void pushBack(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (tail_ == nullptr) {
            head_ = tail_ = newNode;
        } else {
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
        }
        size_++;
    }

    int popFront() {
        if (empty()) throw runtime_error("List is empty");
        DLLNode* temp = head_;
        int val = temp->data;

        head_ = head_->next;
        if (head_ != nullptr) {
            head_->prev = nullptr;
        } else {
            tail_ = nullptr; // list became empty
        }

        delete temp;
        size_--;
        return val;
    }

    int popBack() {
        if (empty()) throw runtime_error("List is empty");
        DLLNode* temp = tail_;
        int val = temp->data;

        tail_ = tail_->prev;
        if (tail_ != nullptr) {
            tail_->next = nullptr;
        } else {
            head_ = nullptr; // list became empty
        }

        delete temp;
        size_--;
        return val;
    }

    bool empty() const {
        return head_ == nullptr;
    }

    size_t size() const {
        return size_;
    }

    vector<int> toForwardVector() const {
        vector<int> res;
        DLLNode* curr = head_;
        while (curr != nullptr) {
            res.push_back(curr->data);
            curr = curr->next;
        }
        return res;
    }

    vector<int> toBackwardVector() const {
        vector<int> res;
        DLLNode* curr = tail_;
        while (curr != nullptr) {
            res.push_back(curr->data);
            curr = curr->prev;
        }
        return res;
    }

private:
    DLLNode* head_;
    DLLNode* tail_;
    size_t size_;
};
