#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 02_doubly_linked_list
//    OR:
//    .\run_tests.bat 02_doubly_linked_list
// ============================================================================

// EXERCISE 3.2: Doubly Linked List (DLL)
// CADT DSA Week 3 - Doubly Linked List
//
// TASKS:
// Implement a Doubly Linked List with head_ and tail_ pointers.
// Each Node contains: int `data`, `DLLNode* prev`, `DLLNode* next`.
//
// Required Methods:
// 1. pushFront(val): Insert at head - O(1)
// 2. pushBack(val):  Insert at tail - O(1)
// 3. popFront():     Remove and return head value - O(1) (throws if empty)
// 4. popBack():      Remove and return tail value - O(1) (throws if empty)
// 5. toForwardVector():  Traverse head -> tail via next pointers
// 6. toBackwardVector(): Traverse tail -> head via prev pointers
//    (THIS VERIFIES YOUR PREV POINTERS ARE FULLY SOUND AND NOT BROKEN!)
// 7. ~DoublyLinkedList(): Destructor to delete all nodes cleanly.

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
        // TODO: Create node, set node->next = head_, update head_->prev, update head_
        // Remember to set tail_ = new node if list was previously empty!
        (void)val;
    }

    void pushBack(int val) {
        // TODO: Create node, set node->prev = tail_, update tail_->next, update tail_
        // Remember to set head_ = new node if list was previously empty!
        (void)val;
    }

    int popFront() {
        // TODO: Throw if empty. Update head_, update new head_->prev = nullptr.
        // If list becomes empty, set tail_ = nullptr too!
        if (empty()) throw runtime_error("List is empty");
        return 0;
    }

    int popBack() {
        // TODO: Throw if empty. Update tail_, update new tail_->next = nullptr.
        // If list becomes empty, set head_ = nullptr too!
        if (empty()) throw runtime_error("List is empty");
        return 0;
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
