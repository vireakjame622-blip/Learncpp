#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_circular_linked_list
//    OR:
//    .\run_tests.bat 03_circular_linked_list
// ============================================================================

// EXERCISE 3.3: Circular Linked List (CLL)
// CADT DSA Week 3 - Circular Linked List
//
// TASKS:
// Implement a Circular Linked List where the last node points back to the head node.
//
// Required Methods:
// 1. pushBack(val): Insert val at the end and maintain circular loop back to head_
// 2. empty(): Check if list is empty
// 3. size(): Return number of nodes
// 4. toVector(): Traverse exactly ONE complete cycle and return values
// 5. josephusEliminate(step):
//    - Solves the classic circular elimination problem:
//      Start at head, count `step` nodes, eliminate that node from the circle,
//      and repeat with the remaining nodes until only 1 survivor node remains!
//    - Returns the value of the final survivor node.
// 6. ~CircularLinkedList(): Destructor that cleanly frees the circular loop without infinite loop!

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
        // Break the cycle first to prevent infinite loop during deletion
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
        // TODO:
        // 1. If empty, create node, node->next = node (points to itself!), head_ = node.
        // 2. If not empty, traverse to node whose next is head_, link it to new node,
        //    and set new node->next = head_.
        (void)val;
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
        // TODO:
        // While size_ > 1:
        //   count `step - 1` nodes to find predecessor
        //   unlink and delete target node, update size_
        // Return survivor node's data.
        if (empty() || step <= 0) throw invalid_argument("Invalid list or step");
        return head_->data;
    }

private:
    CLLNode* head_;
    size_t size_;
};
