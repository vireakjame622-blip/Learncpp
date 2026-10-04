#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

int main() {
    TEST_SUITE("03_array_algorithms (Min/Max, Avg Precision & In-Place Reverse)");

    vector<int> emptyVec;
    vector<int> single = {42};
    vector<int> mixed = {12, -7, 45, 0, 89, -23, 89, 4};
    vector<int> intsForAvg = {1, 2}; // sum=3, size=2, avg MUST be 1.5, not 1.0!

    // Condition 1: Empty vectors must throw
    TEST_THROWS(findMax(emptyVec), invalid_argument, "findMax(empty) throws", "Guard empty array with throw");
    TEST_THROWS(findMin(emptyVec), invalid_argument, "findMin(empty) throws", "Guard empty array with throw");
    TEST_THROWS(calculateAverage(emptyVec), invalid_argument, "calculateAverage(empty) throws", "Guard empty array with throw");

    // Condition 2: Single element vector
    TEST_EQUAL(findMax(single), 42, "findMax single element", "Max of [42] is 42");
    TEST_EQUAL(findMin(single), 42, "findMin single element", "Min of [42] is 42");
    TEST_EQUAL(calculateAverage(single), 42.0, "calculateAverage single element", "Avg of [42] is 42.0");

    // Condition 3: Mixed array
    TEST_EQUAL(findMax(mixed), 89, "findMax mixed array with duplicates", "Max should find 89");
    TEST_EQUAL(findMin(mixed), -23, "findMin negative numbers", "Min should find -23");

    // Condition 4: Floating point division accuracy (no integer truncation!)
    double avg = calculateAverage(intsForAvg);
    TEST_CONDITION(abs(avg - 1.5) < 0.0001, "Average of {1, 2} is 1.5 (avoid integer division!)", "Did you do (sum / size) as ints? Cast to double first: static_cast<double>(sum) / size");

    // Condition 5: In-place reversal of even length
    vector<int> evenArr = {1, 2, 3, 4};
    vector<int> expectedEven = {4, 3, 2, 1};
    reverseInPlace(evenArr);
    TEST_CONDITION(evenArr == expectedEven, "reverseInPlace even length {1,2,3,4} -> {4,3,2,1}", "Check two-pointer swapping");

    // Condition 6: In-place reversal of odd length
    vector<int> oddArr = {10, 20, 30, 40, 50};
    vector<int> expectedOdd = {50, 40, 30, 20, 10};
    reverseInPlace(oddArr);
    TEST_CONDITION(oddArr == expectedOdd, "reverseInPlace odd length {10,20,30,40,50}", "Middle element remains in place");

    TEST_REPORT();
}
