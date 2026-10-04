#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <cmath>

using namespace std;

int main() {
    TEST_SUITE("02_operator_overloading (Vector2D Mathematical Algebra)");

    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    // Condition 1: Magnitude and toString
    {
        TEST_EQUAL(v1.magnitude(), 5.0, "Vector (3, 4) has magnitude 5.0", "Pythagorean theorem");
        TEST_EQUAL(v1.toString(), "(3.0, 4.0)", "toString returns formatted string", "Check formatting");
    }

    // Condition 2: Addition and Subtraction
    {
        Vector2D sum = v1 + v2;
        TEST_EQUAL(sum.x(), 4.0, "(3,4) + (1,2) -> x is 4.0", "operator+ x component");
        TEST_EQUAL(sum.y(), 6.0, "(3,4) + (1,2) -> y is 6.0", "operator+ y component");

        Vector2D diff = v1 - v2;
        TEST_EQUAL(diff.x(), 2.0, "(3,4) - (1,2) -> x is 2.0", "operator- x component");
        TEST_EQUAL(diff.y(), 2.0, "(3,4) - (1,2) -> y is 2.0", "operator- y component");
    }

    // Condition 3: Scalar multiplication & Dot product
    {
        Vector2D scaled = v1 * 2.0;
        TEST_EQUAL(scaled.x(), 6.0, "v1 * 2 -> x is 6.0", "scalar multiplication");
        TEST_EQUAL(scaled.y(), 8.0, "v1 * 2 -> y is 8.0", "scalar multiplication");

        Vector2D leftScaled = 2.0 * v1;
        TEST_EQUAL(leftScaled.x(), 6.0, "2 * v1 -> x is 6.0 (commutative)", "free function operator*");

        double dotProd = v1.dot(v2); // 3*1 + 4*2 = 11
        TEST_EQUAL(dotProd, 11.0, "(3,4) dot (1,2) is 11.0", "dot product calculation");
    }

    // Condition 4: Unary negation
    {
        Vector2D neg = -v1;
        TEST_EQUAL(neg.x(), -3.0, "-(3, 4) -> x is -3.0", "unary operator-");
        TEST_EQUAL(neg.y(), -4.0, "-(3, 4) -> y is -4.0", "unary operator-");
    }

    // Condition 5: Equality & Inequality operators
    {
        Vector2D clone(3.0, 4.0);
        TEST_CONDITION(v1 == clone, "v1 == clone returns true", "operator==");
        TEST_CONDITION(v1 != v2, "v1 != v2 returns true", "operator!=");
    }

    TEST_REPORT();
}
