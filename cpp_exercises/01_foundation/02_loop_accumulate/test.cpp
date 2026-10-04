#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("02_loop_accumulate (Loops, Totals & Factorials)");

    // Condition 1: sumRange standard & reverse
    TEST_EQUAL(sumRange(1, 5), 15LL, "sumRange(1, 5) == 15", "1+2+3+4+5 = 15");
    TEST_EQUAL(sumRange(5, 1), 15LL, "sumRange(5, 1) == 15 (reversed input)", "Handle a > b by swapping");
    TEST_EQUAL(sumRange(-3, 3), 0LL, "sumRange(-3, 3) == 0", "Negatives cancel out with positives");
    TEST_EQUAL(sumRange(7, 7), 7LL, "sumRange(7, 7) == 7 (single number)", "Loop executes exactly once");

    // Condition 2: countDigits edge cases
    TEST_EQUAL(countDigits(0), 1, "countDigits(0) == 1", "0 has 1 digit!");
    TEST_EQUAL(countDigits(9), 1, "countDigits(9) == 1", "Single digit");
    TEST_EQUAL(countDigits(123456789), 9, "countDigits(123456789) == 9", "Positive multi-digit");
    TEST_EQUAL(countDigits(-42), 2, "countDigits(-42) == 2", "Negative sign should not be counted as a digit");
    TEST_EQUAL(countDigits(-100000), 6, "countDigits(-100000) == 6", "Negative large number");

    // Condition 3: factorial conditions
    TEST_EQUAL(factorial(0), 1LL, "factorial(0) == 1", "By definition, 0! = 1");
    TEST_EQUAL(factorial(1), 1LL, "factorial(1) == 1", "1! = 1");
    TEST_EQUAL(factorial(5), 120LL, "factorial(5) == 120", "5! = 120");
    TEST_EQUAL(factorial(10), 3628800LL, "factorial(10) == 3628800", "10! = 3628800");
    TEST_THROWS(factorial(-5), invalid_argument, "factorial(-5) throws invalid_argument", "Factorial is undefined for negative integers");

    // Condition 4: generateMultiplicationTable
    auto table7 = generateMultiplicationTable(7, 5);
    vector<int> expected7 = {7, 14, 21, 28, 35};
    TEST_EQUAL(table7.size(), 5ULL, "table size for 7 up to 5 is 5", "Vector should have 5 elements");
    TEST_CONDITION(table7 == expected7, "table values for 7x1..7x5 match {7,14,21,28,35}", "Check table calculation");

    auto emptyTable = generateMultiplicationTable(5, 0);
    TEST_CONDITION(emptyTable.empty(), "table upTo 0 returns empty vector", "When upTo <= 0, return empty");

    TEST_REPORT();
}
