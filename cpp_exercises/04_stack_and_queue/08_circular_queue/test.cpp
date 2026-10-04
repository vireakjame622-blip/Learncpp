#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("08_circular_queue (Modulo Ring Buffer & Full/Empty Exceptions)");

    CircularQueue cq(3); // capacity 3

    // Condition 1: Initial state & empty throws
    TEST_CONDITION(cq.empty(), "New queue is empty", "empty() is true");
    TEST_CONDITION(!cq.full(), "New queue is not full", "full() is false");
    TEST_EQUAL(cq.size(), 0ULL, "Initial size is 0", "size is 0");
    TEST_EQUAL(cq.capacity(), 3ULL, "Capacity is 3", "capacity is 3");
    TEST_THROWS(cq.dequeue(), runtime_error, "dequeue() on empty throws", "Guard empty");
    TEST_THROWS(cq.front(), runtime_error, "front() on empty throws", "Guard empty");
    TEST_THROWS(cq.rear(), runtime_error, "rear() on empty throws", "Guard empty");

    // Condition 2: Fill to capacity
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    TEST_EQUAL(cq.size(), 3ULL, "Size is 3 when filled", "Check size");
    TEST_CONDITION(cq.full(), "Queue reports full() == true", "full() when size == capacity");
    TEST_THROWS(cq.enqueue(40), runtime_error, "enqueue() on full queue throws runtime_error", "Guard full enqueue");

    if (!cq.empty()) {
        TEST_EQUAL(cq.front(), 10, "front() is 10", "First element is 10");
        TEST_EQUAL(cq.rear(), 30, "rear() is 30", "Last element is 30");
    }

    // Condition 3: Dequeue and wraparound enqueue (Ring Buffer verification)
    if (!cq.empty()) {
        cq.dequeue(); // removes 10 -> [empty, 20, 30]
        TEST_CONDITION(!cq.full(), "Queue no longer full after dequeue", "Size is 2");
        TEST_EQUAL(cq.front(), 20, "front() is now 20", "Next element is 20");

        // Enqueue 40: Should wrap around into index 0 of the internal buffer!
        cq.enqueue(40);
        TEST_CONDITION(cq.full(), "Queue full again after wraparound enqueue", "Wraparound enqueue succeeded");
        TEST_EQUAL(cq.front(), 20, "front() is still 20", "Front unchanged");
        TEST_EQUAL(cq.rear(), 40, "rear() is 40 at wrapped index", "Rear updated to 40");
    }

    TEST_REPORT();
}
