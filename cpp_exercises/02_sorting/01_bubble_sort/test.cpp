#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    TEST_SUITE("01_bubble_sort (Adjacent Comparisons & Early Exit)");

    // Condition 1: Empty and single element
    vector<int> emptyVec;
    bubbleSort(emptyVec);
    TEST_CONDITION(emptyVec.empty(), "Empty array remains empty without error", "Guard n <= 1");

    vector<int> single = {42};
    bubbleSort(single);
    TEST_CONDITION(single.size() == 1 && single[0] == 42, "Single element [42] remains unchanged", "Guard n <= 1");

    // Condition 2: Standard unsorted array
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> expected1 = {11, 12, 22, 25, 34, 64, 90};
    bubbleSort(arr1);
    TEST_CONDITION(arr1 == expected1, "Sorts standard random array {64, 34, 25, 12, 22, 11, 90}", "Check adjacent comparison and swapping");

    // Condition 3: Already sorted array
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> expected2 = {1, 2, 3, 4, 5};
    bubbleSort(arr2);
    TEST_CONDITION(arr2 == expected2, "Already sorted array remains sorted", "Check early exit optimization");

    // Condition 4: Reverse sorted array
    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> expected3 = {1, 2, 3, 4, 5};
    bubbleSort(arr3);
    TEST_CONDITION(arr3 == expected3, "Reverse sorted array sorted correctly", "Worst case O(n^2)");

    // Condition 5: Array with negative numbers and duplicates
    vector<int> arr4 = {3, -1, 2, 3, -1, 0, 5};
    vector<int> expected4 = {-1, -1, 0, 2, 3, 3, 5};
    bubbleSort(arr4);
    TEST_CONDITION(arr4 == expected4, "Handles duplicates and negative numbers correctly", "Preserve order of equals");

    TEST_REPORT();
}
