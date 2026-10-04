#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("06_queue_linked_nodes (Week 4 Lab: Custom FIFO & The 'Rear Bug')");

    NodeQueue q;

    // Condition 1: Initial state & guard empty case
    TEST_CONDITION(q.empty(), "New NodeQueue is empty", "front_ is nullptr");
    TEST_EQUAL(q.size(), 0ULL, "Initial size is 0", "size_ is 0");
    TEST_THROWS(q.dequeue(), runtime_error, "Guard empty case: dequeue() throws runtime_error", "Check empty()");
    TEST_THROWS(q.front(), runtime_error, "Guard empty case: front() throws runtime_error", "Check empty()");

    // Condition 2: enqueue multiple items
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    TEST_CONDITION(!q.empty(), "Queue is not empty after enqueues", "empty() is false");
    TEST_EQUAL(q.size(), 3ULL, "Queue size is 3", "Check size increment");
    if (!q.empty()) {
        TEST_EQUAL(q.front(), 10, "front() is 10 (First In, First Out)", "Check front_->data");
    } else {
        TEST_CONDITION(false, "front() is 10", "enqueue() not yet implemented");
    }

    // Condition 3: dequeue advances front
    if (!q.empty()) {
        q.dequeue(); // removes 10
        TEST_EQUAL(q.size(), 2ULL, "Size is 2 after 1 dequeue", "Check size decrement");
        TEST_EQUAL(q.front(), 20, "front() is now 20", "Next element is front");
    } else {
        TEST_CONDITION(false, "dequeue check", "enqueue() not yet implemented");
    }

    // Condition 4: ⚠️ CRITICAL TEST — The "Rear Bug" (Slide 14)
    // Dequeue until only 1 element remains, then dequeue that last element!
    // Both front_ AND rear_ MUST become nullptr!
    if (!q.empty()) {
        q.dequeue(); // removes 20 -> only 30 remains
        TEST_EQUAL(q.size(), 1ULL, "Queue has exactly 1 element left", "Check size is 1");
        q.dequeue(); // removes 30 -> empty!
        TEST_CONDITION(q.empty(), "Queue is empty after removing last element", "front_ is nullptr");
        TEST_CONDITION(q.getRear() == nullptr, "Rear pointer is nullptr after last dequeue (NO DANGLING REAR POINTER BUG!)", 
                       "Slide 14 Fix: Did you do if (front_ == nullptr) rear_ = nullptr; in dequeue()?");
    } else {
        TEST_CONDITION(false, "Rear bug check", "Queue empty");
    }

    // Condition 5: Re-enqueueing after queue became completely empty
    // If the rear bug was present, this next enqueue would crash or corrupt!
    q.enqueue(999);
    TEST_CONDITION(!q.empty() && q.size() == 1, "Successfully re-enqueued after becoming empty", "Fresh enqueue after empty state");
    if (!q.empty()) {
        TEST_EQUAL(q.front(), 999, "front() of re-enqueued queue is 999", "Check new node");
    }

    TEST_REPORT();
}
