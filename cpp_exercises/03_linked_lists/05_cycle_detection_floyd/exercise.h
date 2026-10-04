#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 05_cycle_detection_floyd
//    OR:
//    .\run_tests.bat 05_cycle_detection_floyd
// ============================================================================

// EXERCISE 3.5: Cycle Detection (Floyd's Tortoise & Hare Algorithm)
// CADT Advanced Algorithm & C++ • Week 3
//
// TASKS:
// 1. hasCycle(Node* head):
//    - Return true if the singly linked list contains a cycle, false otherwise.
//    - Must run in O(n) time and O(1) auxiliary space using slow (1x) and fast (2x) pointers.
// 2. getCycleLength(Node* head):
//    - If a cycle exists, return the exact number of nodes in the cycle.
//    - Return 0 if the list has no cycle.
// 3. getCycleEntry(Node* head):
//    - Return the pointer to the node where the cycle begins (rendezvous point), or nullptr if no cycle.

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

inline bool hasCycle(Node* head) {
    // TODO: Implement Floyd's cycle detection algorithm
    // 1. Use two pointers: slow moving 1 step, fast moving 2 steps
    // 2. If fast or fast->next becomes nullptr, there is no cycle (return false)
    // 3. If slow == fast, a cycle is trapped! (return true)
    (void)head;
    return false;
}

inline size_t getCycleLength(Node* head) {
    // TODO: If a cycle exists, count how many steps it takes for slow to complete one cycle loop
    (void)head;
    return 0;
}

inline Node* getCycleEntry(Node* head) {
    // TODO: Floyd phase 2 rendezvous - return cycle start node, or nullptr if no cycle
    (void)head;
    return nullptr;
}

inline Node* createListWithCycle(const vector<int>& vals, int cyclePos) {
    if (vals.empty()) return nullptr;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    Node* cycleTarget = (cyclePos == 0) ? head : nullptr;

    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
        if (static_cast<int>(i) == cyclePos) {
            cycleTarget = curr;
        }
    }
    if (cyclePos >= 0 && cycleTarget) {
        curr->next = cycleTarget;
    }
    return head;
}

inline void freeLinearList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
