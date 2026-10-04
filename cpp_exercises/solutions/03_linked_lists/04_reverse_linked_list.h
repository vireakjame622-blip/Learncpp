#pragma once
#include <vector>

using namespace std;

// Verified Solution for Exercise 3.4: Reverse Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

inline ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
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
