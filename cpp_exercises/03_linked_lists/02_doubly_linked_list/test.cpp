#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

int main() {
    TEST_SUITE("02_doubly_linked_list (Prev/Next Links & Bidirectional Invariant)");

    DoublyLinkedList dll;

    // Condition 1: Initial state & empty throws
    TEST_CONDITION(dll.empty(), "New DLL is empty", "Initial head_ and tail_ are nullptr");
    TEST_EQUAL(dll.size(), 0ULL, "Initial DLL size is 0", "Size initialized to 0");
    TEST_THROWS(dll.popFront(), runtime_error, "popFront() on empty throws", "Guard empty");
    TEST_THROWS(dll.popBack(), runtime_error, "popBack() on empty throws", "Guard empty");

    // Condition 2: pushBack and bidirectional check
    dll.pushBack(10);
    dll.pushBack(20);
    dll.pushBack(30);
    vector<int> expectedFwd = {10, 20, 30};
    vector<int> expectedBwd = {30, 20, 10};
    TEST_CONDITION(dll.toForwardVector() == expectedFwd, "Forward traversal is {10, 20, 30}", "Check next pointers");
    TEST_CONDITION(dll.toBackwardVector() == expectedBwd, "Backward traversal is {30, 20, 10}", "Check prev pointers are correctly linked!");
    TEST_EQUAL(dll.size(), 3ULL, "Size after 3 pushBacks is 3", "Check size increment");

    // Condition 3: pushFront
    dll.pushFront(5);
    vector<int> fwdAfterFront = {5, 10, 20, 30};
    vector<int> bwdAfterFront = {30, 20, 10, 5};
    TEST_CONDITION(dll.toForwardVector() == fwdAfterFront, "Forward after pushFront(5) is {5, 10, 20, 30}", "Update head_->prev on pushFront");
    TEST_CONDITION(dll.toBackwardVector() == bwdAfterFront, "Backward after pushFront(5) is {30, 20, 10, 5}", "Tail still reaches new front node via prev");

    // Condition 4: popBack
    if (!dll.empty()) {
        int backVal = dll.popBack();
        TEST_EQUAL(backVal, 30, "popBack() returns 30", "Return old tail value");
    } else {
        TEST_CONDITION(false, "popBack() returns 30", "List is empty (pushBack not yet implemented)");
    }

    // Condition 5: popFront
    if (!dll.empty()) {
        int frontVal = dll.popFront();
        TEST_EQUAL(frontVal, 5, "popFront() returns 5", "Return old head value");
    } else {
        TEST_CONDITION(false, "popFront() returns 5", "List is empty (pushFront not yet implemented)");
    }

    // Condition 6: Emptying DLL to 0 elements (check head and tail reset)
    while (!dll.empty()) {
        dll.popFront();
    }
    TEST_CONDITION(dll.empty(), "DLL is empty after removing all elements", "Both head_ and tail_ must be nullptr");
    TEST_EQUAL(dll.size(), 0ULL, "DLL size is 0", "Check size reset");

    TEST_REPORT();
}
