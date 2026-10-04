#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("07_queue_using_two_stacks (FIFO via 2x LIFO Inversion)");

    QueueTwoStacks q;

    // Condition 1: Initial state & empty throws
    TEST_CONDITION(q.empty(), "New queue is empty", "empty() is true");
    TEST_EQUAL(q.size(), 0ULL, "Initial size is 0", "size is 0");
    TEST_THROWS(q.dequeue(), runtime_error, "dequeue() on empty throws runtime_error", "Guard empty");
    TEST_THROWS(q.front(), runtime_error, "front() on empty throws runtime_error", "Guard empty");

    // Condition 2: Enqueue 3 elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    TEST_EQUAL(q.size(), 3ULL, "Queue size is 3 after enqueues", "size is 3");
    if (!q.empty()) {
        TEST_EQUAL(q.front(), 1, "front() is 1 (FIFO order)", "1 was pushed first");
    } else {
        TEST_CONDITION(false, "front() is 1", "enqueue() not yet implemented");
    }

    // Condition 3: Dequeue 1 element
    if (!q.empty()) {
        q.dequeue(); // removes 1
        TEST_EQUAL(q.front(), 2, "front() is now 2", "2 was pushed second");
        TEST_EQUAL(q.size(), 2ULL, "Queue size is 2", "size decrement");
    } else {
        TEST_CONDITION(false, "dequeue check", "enqueue() not yet implemented");
    }

    // Condition 4: Interleaved enqueue and dequeue (Tests in_stack -> out_stack dynamic transfer)
    q.enqueue(4); // queue now has 2, 3, 4
    TEST_EQUAL(q.size(), 3ULL, "Queue size is 3 after enqueuing 4", "size increment");
    if (!q.empty()) {
        TEST_EQUAL(q.front(), 2, "front() is still 2", "out_stack_ head is 2");
        q.dequeue(); // removes 2 -> remaining 3, 4
        TEST_EQUAL(q.front(), 3, "front() is now 3", "Next is 3");
        q.dequeue(); // removes 3 -> remaining 4
        TEST_EQUAL(q.front(), 4, "front() is now 4 (shifted from in_stack)", "Transferred from in_stack");
        q.dequeue(); // removes 4 -> empty
        TEST_CONDITION(q.empty(), "Queue is empty after removing all", "Both stacks empty");
    }

    TEST_REPORT();
}
