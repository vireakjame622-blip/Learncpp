#include "exercise.h"
#include "../../include/test_framework.hpp"

using namespace std;

int main() {
    TEST_SUITE("05_cycle_detection_floyd (Tortoise and Hare Algorithm)");

    // Condition 1: Empty and single node without cycle
    {
        TEST_CONDITION(hasCycle(nullptr) == false, "nullptr has no cycle", "Guard null");
        TEST_EQUAL(getCycleLength(nullptr), static_cast<size_t>(0), "Cycle length of nullptr is 0", "Null check");
        TEST_CONDITION(getCycleEntry(nullptr) == nullptr, "Cycle entry of nullptr is nullptr", "Null check");

        Node single(10);
        TEST_CONDITION(hasCycle(&single) == false, "Single node without cycle returns false", "next is null");
        TEST_EQUAL(getCycleLength(&single), static_cast<size_t>(0), "Single node cycle length is 0", "No loop");
    }

    // Condition 2: Linear multi-node list (No cycle)
    {
        Node n1(1), n2(2), n3(3), n4(4);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;

        TEST_CONDITION(hasCycle(&n1) == false, "Linear list 1->2->3->4 has no cycle", "Linear termination");
        TEST_EQUAL(getCycleLength(&n1), static_cast<size_t>(0), "Linear list cycle length is 0", "Return 0 on no cycle");
        TEST_CONDITION(getCycleEntry(&n1) == nullptr, "Linear list cycle entry is nullptr", "Return nullptr on no cycle");
    }

    // Condition 3: Full cycle (Head connects to head)
    {
        Node n1(1), n2(2), n3(3);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n1; // Cycle: 1->2->3->1

        TEST_CONDITION(hasCycle(&n1) == true, "Full circle 1->2->3->1 has cycle", "Detect cycle at head");
        TEST_EQUAL(getCycleLength(&n1), static_cast<size_t>(3), "Cycle length is 3", "Count loop nodes");
        TEST_CONDITION(getCycleEntry(&n1) == &n1, "Cycle entry is n1 (head)", "Entry point is node 1");
    }

    // Condition 4: Partial cycle (Lasso shape: 1 -> 2 -> 3 -> 4 -> 2)
    {
        Node n1(10), n2(20), n3(30), n4(40);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n2; // Loop back to n2 (20)

        TEST_CONDITION(hasCycle(&n1) == true, "Lasso list 10->20->30->40->20 has cycle", "Detect cycle in middle");
        TEST_EQUAL(getCycleLength(&n1), static_cast<size_t>(3), "Loop 20->30->40 has length 3", "Count inner loop");
        TEST_CONDITION(getCycleEntry(&n1) == &n2, "Cycle entry point is n2 (20)", "Floyd phase 2 pointer rendezvous");
    }

    TEST_REPORT();
}
