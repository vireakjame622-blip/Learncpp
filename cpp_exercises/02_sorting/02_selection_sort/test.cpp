#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("02_selection_sort (Find Minimum & Swap to Prefix)");

    // Condition 1: Empty and single
    vector<int> emptyVec;
    selectionSort(emptyVec);
    TEST_CONDITION(emptyVec.empty(), "Empty array remains empty", "Guard n <= 1");

    vector<int> single = {100};
    selectionSort(single);
    TEST_CONDITION(single.size() == 1 && single[0] == 100, "Single element remains [100]", "Guard n <= 1");

    // Condition 2: General unsorted
    vector<int> arr1 = {29, 10, 14, 37, 13};
    vector<int> expected1 = {10, 13, 14, 29, 37};
    selectionSort(arr1);
    TEST_CONDITION(arr1 == expected1, "Sorts unsorted array {29, 10, 14, 37, 13}", "Check minIndex finding and swap");

    // Condition 3: Negatives and duplicates
    vector<int> arr2 = {-5, 20, -5, 0, 15, -20};
    vector<int> expected2 = {-20, -5, -5, 0, 15, 20};
    selectionSort(arr2);
    TEST_CONDITION(arr2 == expected2, "Sorts negatives and duplicate values", "Ensure minIndex comparison allows duplicate values");

    // Condition 4: Reverse sorted
    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> expected3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    selectionSort(arr3);
    TEST_CONDITION(arr3 == expected3, "Sorts descending array", "Verify full sort");

    TEST_REPORT();
}
