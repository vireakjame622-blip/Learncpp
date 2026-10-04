#include "exercise.h"
#include "../../include/test_framework.hpp"

using namespace std;

int main() {
    TEST_SUITE("05_pointers_and_references (Pass-by-Ref, Pointer Swapping & Safety)");

    // Condition 1: swapByReference modifies original variables
    int x = 10, y = 20;
    swapByReference(x, y);
    TEST_EQUAL(x, 20, "swapByReference modified x", "x should now be 20");
    TEST_EQUAL(y, 10, "swapByReference modified y", "y should now be 10");

    // Condition 2: swapByPointer modifies pointed values
    int p1 = 100, p2 = 200;
    bool swapOk = swapByPointer(&p1, &p2);
    TEST_CONDITION(swapOk == true, "swapByPointer returned true for valid pointers", "Return true when swap succeeds");
    TEST_EQUAL(p1, 200, "swapByPointer modified p1", "p1 should now be 200");
    TEST_EQUAL(p2, 100, "swapByPointer modified p2", "p2 should now be 100");

    // Condition 3: swapByPointer guard conditions for nullptr (prevent segmentation fault)
    int valid = 50;
    bool nullCheck1 = swapByPointer(nullptr, &valid);
    bool nullCheck2 = swapByPointer(&valid, nullptr);
    bool nullCheck3 = swapByPointer(nullptr, nullptr);
    TEST_CONDITION(nullCheck1 == false && nullCheck2 == false && nullCheck3 == false, "swapByPointer safely rejects nullptr", "Guard: if (!a || !b) return false;");
    TEST_EQUAL(valid, 50, "valid variable untouched after nullptr swap", "Do not alter memory if null");

    // Condition 4: clampValue
    int valLow = -15;
    clampValue(&valLow, 0, 100);
    TEST_EQUAL(valLow, 0, "clampValue below min clamped to 0", "Value < minVal should become minVal");

    int valHigh = 150;
    clampValue(&valHigh, 0, 100);
    TEST_EQUAL(valHigh, 100, "clampValue above max clamped to 100", "Value > maxVal should become maxVal");

    int valMid = 55;
    clampValue(&valMid, 0, 100);
    TEST_EQUAL(valMid, 55, "clampValue within range untouched", "Value between min and max stays the same");

    clampValue(nullptr, 0, 100); // must not crash
    TEST_CONDITION(true, "clampValue with nullptr handled without crash", "Guard against null pointer");

    // Condition 5: sumArrayViaPointer
    int numbers[] = {1, 2, 3, 4, 5, 10};
    int total = sumArrayViaPointer(numbers, 6);
    TEST_EQUAL(total, 25, "sumArrayViaPointer matches sum", "1+2+3+4+5+10 = 25");
    TEST_EQUAL(sumArrayViaPointer(nullptr, 5), 0, "sumArrayViaPointer on null returns 0", "Check for nullptr");
    TEST_EQUAL(sumArrayViaPointer(numbers, 0), 0, "sumArrayViaPointer on size 0 returns 0", "Check for size 0");

    TEST_REPORT();
}
