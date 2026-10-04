#pragma once
#include <cstddef>

using namespace std;

// Verified Solution for Exercise 3.5: Cycle Detection (Floyd's Algorithm)
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

inline bool hasCycle(Node* head) {
    if (!head || !head->next) return false;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

inline size_t getCycleLength(Node* head) {
    if (!head || !head->next) return 0;
    Node* slow = head;
    Node* fast = head;
    bool found = false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            found = true;
            break;
        }
    }
    if (!found) return 0;

    size_t length = 1;
    Node* curr = slow->next;
    while (curr != slow) {
        length++;
        curr = curr->next;
    }
    return length;
}

inline Node* getCycleEntry(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* slow = head;
    Node* fast = head;
    bool found = false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            found = true;
            break;
        }
    }
    if (!found) return nullptr;

    Node* p1 = head;
    Node* p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
