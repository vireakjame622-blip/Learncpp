#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("01_singly_linked_list (Nodes, Dynamic Allocation & Destructor)");

    SinglyLinkedList list;

    // Condition 1: Initial state
    TEST_CONDITION(list.empty() == true, "New list is empty", "Initial head should be nullptr");
    TEST_EQUAL(list.size(), 0ULL, "Initial size is 0", "Initial size_ should be 0");
    TEST_THROWS(list.popFront(), runtime_error, "popFront() on empty list throws runtime_error", "Check empty() before popping");

    // Condition 2: pushFront
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    vector<int> expectedFront = {30, 20, 10};
    TEST_CONDITION(list.toVector() == expectedFront, "pushFront builds {30, 20, 10}", "Front insertion reverses input order");
    TEST_EQUAL(list.size(), 3ULL, "List size after 3 pushFronts is 3", "Increment size_ on push");

    // Condition 3: pushBack
    list.pushBack(40);
    vector<int> expectedBack = {30, 20, 10, 40};
    TEST_CONDITION(list.toVector() == expectedBack, "pushBack appends 40 to end", "Traverse to last node and link");
    TEST_EQUAL(list.size(), 4ULL, "List size is now 4", "Increment size_ on pushBack");

    // Condition 4: contains
    TEST_CONDITION(list.contains(20) == true, "contains(20) returns true", "Search existing value");
    TEST_CONDITION(list.contains(999) == false, "contains(999) returns false", "Search missing value");

    // Condition 5: popFront
    if (!list.empty()) {
        int val = list.popFront();
        TEST_EQUAL(val, 30, "popFront() returns 30", "Return old head's value");
        vector<int> afterPop = {20, 10, 40};
        TEST_CONDITION(list.toVector() == afterPop, "List after popFront is {20, 10, 40}", "Head moved to next node");
    } else {
        TEST_CONDITION(false, "popFront() returns 30", "List is still empty (pushFront not yet implemented)");
    }

    // Condition 6: deleteValue (middle, head, non-existent)
    bool delMiddle = list.deleteValue(10);
    TEST_CONDITION(delMiddle == true, "deleteValue(10) deletes middle element", "Unlink middle node and delete");

    bool delMissing = list.deleteValue(99);
    TEST_CONDITION(delMissing == false, "deleteValue(99) returns false for missing value", "Return false if value not in list");

    bool delHead = list.deleteValue(20);
    TEST_CONDITION(delHead == true, "deleteValue(20) deletes head element", "Update head_ if first node matches");

    list.deleteValue(40);
    TEST_CONDITION(list.empty() == true, "Deleting last node leaves list empty", "Head should be nullptr, size 0");

    TEST_REPORT();
}
