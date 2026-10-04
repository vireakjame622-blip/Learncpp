#pragma once
#include <vector>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 04_reverse_linked_list
//    OR:
//    .\run_tests.bat 04_reverse_linked_list
// ============================================================================

// EXERCISE 3.4: Reverse Linked List (In-Place Pointer Manipulation)
// CADT Advanced Algorithm & C++ • Week 3
//
// TASK:
// 1. Given the head of a singly linked list, reverse the list in-place
//    in O(n) time and O(1) auxiliary space, and return the new head.
// 2. Implement toVector(ListNode* head) helper to convert a linked list to vector<int>.
// 3. Implement createList(const vector<int>& vals) to build a linked list.
// 4. Implement freeList(ListNode* head) to prevent memory leaks.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

inline ListNode* reverseList(ListNode* head) {
    // TODO: Reverse the linked list in-place using prev, curr, and next pointers.
    // Must run in O(n) time and O(1) auxiliary memory.
    (void)head;
    return nullptr;
}

inline ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

inline vector<int> toVector(ListNode* head) {
    vector<int> result;
    ListNode* curr = head;
    while (curr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

inline void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}
