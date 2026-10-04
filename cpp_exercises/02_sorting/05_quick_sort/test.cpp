#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    TEST_SUITE("05_quick_sort (Pivot Partitioning & Recursion)");

    // Condition 1: Empty and single
    vector<int> emptyVec;
    quickSort(emptyVec);
    TEST_CONDITION(emptyVec.empty(), "Empty array remains empty", "Base case size <= 1");

    vector<int> single = {88};
    quickSort(single);
    TEST_CONDITION(single.size() == 1 && single[0] == 88, "Single element remains [88]", "Base case size <= 1");

    // Condition 2: General unsorted array
    vector<int> arr1 = {10, 80, 30, 90, 40, 50, 70};
    vector<int> expected1 = {10, 30, 40, 50, 70, 80, 90};
    quickSort(arr1);
    TEST_CONDITION(arr1 == expected1, "Sorts unsorted array {10, 80, 30, 90, 40, 50, 70}", "Check pivot partitioning");

    // Condition 3: Array with ALL IDENTICAL elements
    // (Crucial edge case: many buggy Lomuto implementations crash or infinite recurse on identical elements!)
    vector<int> identical = {5, 5, 5, 5, 5, 5};
    vector<int> expectedIdentical = {5, 5, 5, 5, 5, 5};
    quickSort(identical);
    TEST_CONDITION(identical == expectedIdentical, "Handles all-identical elements without infinite recursion", "Partition must terminate safely");

    // Condition 4: Descending array
    vector<int> descending = {9, 7, 5, 3, 1};
    vector<int> expectedDesc = {1, 3, 5, 7, 9};
    quickSort(descending);
    TEST_CONDITION(descending == expectedDesc, "Sorts descending array", "Verify sub-array recursion bounds");

    TEST_REPORT();
}
