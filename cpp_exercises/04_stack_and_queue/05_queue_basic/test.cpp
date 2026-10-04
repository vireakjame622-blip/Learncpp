#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("05_queue_basic (FIFO & Deque Operations)");

    Queue<int> q;

    // Condition 1: Initial state & empty exceptions
    TEST_CONDITION(q.empty(), "New queue is empty", "empty() is true");
    TEST_EQUAL(q.size(), 0ULL, "Initial size is 0", "size is 0");
    TEST_THROWS(q.dequeue(), runtime_error, "dequeue() on empty throws runtime_error", "Guard empty dequeue");
    TEST_THROWS(q.front(), runtime_error, "front() on empty throws runtime_error", "Guard empty front");

    // Condition 2: enqueue & FIFO order (First In, First Out)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    TEST_CONDITION(!q.empty(), "Queue is not empty after enqueues", "Check empty()");
    TEST_EQUAL(q.size(), 3ULL, "Queue size is 3", "Check size()");
    if (!q.empty()) {
        TEST_EQUAL(q.front(), 10, "front() is 10 (FIFO: first enqueued is first out)", "Check front()");

        // Condition 3: dequeue advances front
        q.dequeue(); // removes 10
        TEST_EQUAL(q.size(), 2ULL, "Queue size is 2 after 1 dequeue", "Check size()");
        TEST_EQUAL(q.front(), 20, "front() is now 20", "Next in line is 20");

        // Condition 4: Emptying queue
        q.dequeue(); // removes 20
        q.dequeue(); // removes 30
        TEST_CONDITION(q.empty(), "Queue is empty after dequeuing all", "Check empty()");
        TEST_THROWS(q.dequeue(), runtime_error, "dequeue() on re-emptied queue throws", "Guard empty dequeue");
    } else {
        TEST_CONDITION(false, "enqueue and FIFO check", "enqueue() not yet implemented");
    }

    // Condition 5: Template queue of strings
    Queue<string> strQueue;
    strQueue.enqueue("Job 1");
    strQueue.enqueue("Job 2");
    if (!strQueue.empty()) {
        TEST_EQUAL(strQueue.front(), string("Job 1"), "Queue<string> returns Job 1", "Generic FIFO test");
    } else {
        TEST_CONDITION(false, "Queue<string> returns Job 1", "enqueue() not yet implemented");
    }

    TEST_REPORT();
}
