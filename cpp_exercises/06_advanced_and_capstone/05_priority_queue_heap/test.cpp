#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("03_priority_queue_heap (Binary Min-Heap & Logarithmic Scheduling)");

    MinHeapPriorityQueue pq;

    // Condition 1: Initial state
    {
        TEST_CONDITION(pq.empty() == true, "New PQ is empty", "empty() check");
        TEST_EQUAL(pq.size(), static_cast<size_t>(0), "Initial size is 0", "size() check");
        TEST_THROWS(pq.top(), underflow_error, "top() on empty throws underflow_error", "Empty guard");
        TEST_THROWS(pq.pop(), underflow_error, "pop() on empty throws underflow_error", "Empty guard");
    }

    // Condition 2: Push elements in arbitrary order
    {
        // Pushing: 30, 10, 50, 5, 20
        pq.push(30);
        pq.push(10);
        pq.push(50);
        pq.push(5);
        pq.push(20);

        TEST_EQUAL(pq.size(), static_cast<size_t>(5), "Size is 5 after 5 pushes", "Size tracking");
        TEST_EQUAL(pq.top(), 5, "top() is the absolute minimum (5)", "Min-heap property");
    }

    // Condition 3: Priority extraction (sorted ascending order)
    {
        vector<int> extracted;
        while (!pq.empty()) {
            extracted.push_back(pq.top());
            pq.pop();
        }

        vector<int> expected = {5, 10, 20, 30, 50};
        TEST_CONDITION(extracted == expected, "Repeated pop() yields {5, 10, 20, 30, 50}", "Heap Sort order");
        TEST_CONDITION(pq.empty() == true, "PQ is empty after extracting all elements", "Empty state");
    }

    // Condition 4: Duplicates & Negative numbers
    {
        pq.push(0);
        pq.push(-10);
        pq.push(10);
        pq.push(-10);
        pq.push(0);

        TEST_EQUAL(pq.top(), -10, "top() is -10", "Negative numbers supported");
        pq.pop();
        TEST_EQUAL(pq.top(), -10, "top() is second -10", "Duplicate handling");
        pq.pop();
        TEST_EQUAL(pq.top(), 0, "top() is 0", "Zero handled");
    }

    TEST_REPORT();
}
