#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("04_reverse_linked_list (In-Place Pointer Manipulation)");

    // Condition 1: Empty list
    {
        ListNode* head = nullptr;
        ListNode* rev = reverseList(head);
        TEST_CONDITION(rev == nullptr, "Reversing empty list returns nullptr", "Guard against head == nullptr");
    }

    // Condition 2: Single node
    {
        ListNode* head = createList({42});
        ListNode* rev = reverseList(head);
        vector<int> expected = {42};
        TEST_CONDITION(toVector(rev) == expected, "Reversing single node {42} returns {42}", "Single node edge case");
        freeList(rev);
    }

    // Condition 3: Two nodes
    {
        ListNode* head = createList({10, 20});
        ListNode* rev = reverseList(head);
        vector<int> expected = {20, 10};
        TEST_CONDITION(toVector(rev) == expected, "Reversing {10, 20} returns {20, 10}", "Two nodes link reversal");
        freeList(rev);
    }

    // Condition 4: Multi-node sequence
    {
        ListNode* head = createList({1, 2, 3, 4, 5});
        ListNode* rev = reverseList(head);
        vector<int> expected = {5, 4, 3, 2, 1};
        TEST_CONDITION(toVector(rev) == expected, "Reversing {1, 2, 3, 4, 5} returns {5, 4, 3, 2, 1}", "Iterative pointer redirection");
        freeList(rev);
    }

    // Condition 5: In-place verification (no new nodes allocated)
    {
        ListNode* n1 = new ListNode(100);
        ListNode* n2 = new ListNode(200);
        n1->next = n2;
        ListNode* rev = reverseList(n1);
        TEST_CONDITION(rev == n2, "New head is original tail node", "Must be in-place");
        TEST_CONDITION(rev->next == n1, "n2->next points back to n1", "In-place pointer reversal");
        TEST_CONDITION(n1->next == nullptr, "Original head n1->next is now nullptr", "End of reversed list must be null");
        freeList(rev);
    }

    TEST_REPORT();
}
