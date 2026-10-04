#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 01_singly_linked_list
//    OR:
//    .\run_tests.bat 01_singly_linked_list
// ============================================================================

// EXERCISE 3.1: Singly Linked List
// CADT DSA Week 3 - Singly Linked List (SLL)
//
// TASKS:
// Implement a dynamic Singly Linked List.
// Each Node contains an int `data` and a pointer `next` to the next node.
//
// Required Methods:
// 1. pushFront(val): Insert val at the beginning of the list - O(1)
// 2. pushBack(val):  Insert val at the end of the list - O(n)
// 3. popFront():     Remove and return the value at the front - O(1)
//                    Throw runtime_error("List is empty") if empty!
// 4. deleteValue(val): Delete first node with data == val. Return true if deleted, false if not found.
// 5. contains(val):  Return true if val exists in the list, false otherwise - O(n)
// 6. size():         Return the number of nodes in the list.
// 7. empty():        Return true if the list has 0 nodes.
// 8. toVector():     Convert linked list nodes to vector<int> for inspection.
// 9. ~SinglyLinkedList(): Destructor! Free ALL allocated nodes with delete to prevent memory leaks!

struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SinglyLinkedList() : head_(nullptr), size_(0) {}

    ~SinglyLinkedList() {
        // TODO: Traverse and delete all nodes to prevent memory leaks!
        clear();
    }

    void clear() {
        // TODO: Delete all nodes and reset head_ to nullptr and size_ to 0
        while (head_ != nullptr) {
            SLLNode* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        size_ = 0;
    }

    void pushFront(int val) {
        // TODO: Create new node, point to current head_, update head_, increment size_
        (void)val;
    }

    void pushBack(int val) {
        // TODO: If empty, pushFront(val). Otherwise traverse to last node and link.
        (void)val;
    }

    int popFront() {
        // TODO: Throw runtime_error if empty.
        // Otherwise save head_->data, advance head_, delete old head, decrement size_.
        if (empty()) {
            throw runtime_error("List is empty");
        }
        return 0;
    }

    bool deleteValue(int val) {
        // TODO: Find node with data == val.
        // Update previous node's next pointer, delete target node, decrement size_.
        // Return true if found and deleted, false otherwise.
        (void)val;
        return false;
    }

    bool contains(int val) const {
        // TODO: Traverse list and check if any node has data == val.
        (void)val;
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
