#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("04_min_stack (O(1) Minimum Element Tracking)");

    MinStack ms;

    // Condition 1: Empty state & exceptions
    TEST_CONDITION(ms.empty(), "New MinStack is empty", "empty() is true");
    TEST_EQUAL(ms.size(), 0ULL, "Initial size is 0", "size is 0");
    TEST_THROWS(ms.pop(), runtime_error, "pop() on empty throws runtime_error", "Guard empty pop");
    TEST_THROWS(ms.top(), runtime_error, "top() on empty throws runtime_error", "Guard empty top");
    TEST_THROWS(ms.getMin(), runtime_error, "getMin() on empty throws runtime_error", "Guard empty getMin");

    // Condition 2: Pushing elements and tracking min
    ms.push(5);
    if (!ms.empty()) {
        TEST_EQUAL(ms.getMin(), 5, "Min after push(5) is 5", "Single element is its own min");
        ms.push(3);
        TEST_EQUAL(ms.getMin(), 3, "Min after push(3) is 3", "3 < 5");
        ms.push(7);
        TEST_EQUAL(ms.getMin(), 3, "Min after push(7) is still 3", "7 > 3, min stays 3");
        ms.push(2);
        TEST_EQUAL(ms.getMin(), 2, "Min after push(2) is 2", "2 < 3");
        ms.push(2);
        TEST_EQUAL(ms.getMin(), 2, "Min after push duplicate min (2) is 2", "Duplicate min values");

        // Condition 3: Popping elements and restoring previous minimums
        ms.pop(); // pops 2
        TEST_EQUAL(ms.getMin(), 2, "Min is still 2 after popping duplicate min", "Handle duplicate min correctly");
        ms.pop(); // pops 2
        TEST_EQUAL(ms.getMin(), 3, "Min restored to 3 after popping 2", "Previous minimum restored");
        ms.pop(); // pops 7
        TEST_EQUAL(ms.getMin(), 3, "Min is still 3 after popping 7", "Min remains 3");
        ms.pop(); // pops 3
        TEST_EQUAL(ms.getMin(), 5, "Min restored to 5 after popping 3", "Previous minimum restored");
    } else {
        TEST_CONDITION(false, "Push and min tracking", "push() not yet implemented");
    }

    TEST_REPORT();
}
