#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("03_circular_linked_list (Cycle Traversal & Josephus Elimination)");

    CircularLinkedList cll;

    // Condition 1: Initial state
    TEST_CONDITION(cll.empty(), "New CLL is empty", "Initial head_ is nullptr");
    TEST_EQUAL(cll.size(), 0ULL, "Initial size is 0", "Size initialized to 0");

    // Condition 2: Single node points to itself
    cll.pushBack(100);
    vector<int> expectedSingle = {100};
    TEST_CONDITION(!cll.empty(), "CLL with 1 node is not empty", "Check empty() and pushBack");
    TEST_EQUAL(cll.size(), 1ULL, "CLL size is 1", "Size is 1");
    TEST_CONDITION(cll.toVector() == expectedSingle, "toVector() on single node stops after 1 cycle", "Do-while terminates when curr == head_");

    // Condition 3: Multiple nodes cycle
    cll.pushBack(200);
    cll.pushBack(300);
    cll.pushBack(400);
    vector<int> expectedMulti = {100, 200, 300, 400};
    TEST_CONDITION(cll.toVector() == expectedMulti, "toVector() returns {100, 200, 300, 400}", "Check circular linking back to head");
    TEST_EQUAL(cll.size(), 4ULL, "CLL size is 4", "Check size increment");

    // Condition 4: Josephus elimination
    CircularLinkedList jCircle;
    for (int i = 1; i <= 5; ++i) {
        jCircle.pushBack(i);
    }
    if (!jCircle.empty()) {
        try {
            int survivor = jCircle.josephusEliminate(2);
            TEST_EQUAL(survivor, 3, "Josephus(n=5, step=2) survivor is 3", "Check round-robin elimination");
        } catch (...) {
            TEST_CONDITION(false, "Josephus(n=5, step=2) survivor is 3", "Exception thrown in josephusEliminate");
        }
    } else {
        TEST_CONDITION(false, "Josephus(n=5, step=2) survivor is 3", "List is empty (pushBack not yet implemented)");
    }

    TEST_REPORT();
}
