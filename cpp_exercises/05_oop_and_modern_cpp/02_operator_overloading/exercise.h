#pragma once
#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 02_operator_overloading
//    OR:
//    .\run_tests.bat 02_operator_overloading
// ============================================================================

// EXERCISE 5.2: Operator Overloading (Vector2D Algebra)
// CADT Advanced Algorithm & C++ • Week 2 OOP
//
// TASK:
// Implement a mathematical 2D vector class with overloaded operators:
// 1. operator+(const Vector2D& o) const: vector addition (x1+x2, y1+y2)
// 2. operator-(const Vector2D& o) const: vector subtraction (x1-x2, y1-y2)
// 3. operator*(double scalar) const: scalar multiplication (x*s, y*s)
// 4. friend operator*(double s, const Vector2D& v): commutative scalar multiplication
// 5. operator-() const: unary negation (-x, -y)
// 6. dot(const Vector2D& o) const: dot product (x1*x2 + y1*y2)
// 7. magnitude() const: Euclidean length sqrt(x*x + y*y)
// 8. operator==(const Vector2D& o) const and operator!=: floating point equality

class Vector2D {
public:
    Vector2D() : x_(0.0), y_(0.0) {}
    Vector2D(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    Vector2D operator+(const Vector2D& rhs) const {
        // TODO: Implement vector addition
        (void)rhs;
        return Vector2D();
    }

    Vector2D operator-(const Vector2D& rhs) const {
        // TODO: Implement vector subtraction
        (void)rhs;
        return Vector2D();
    }

    Vector2D operator*(double scalar) const {
        // TODO: Implement scalar multiplication
        (void)scalar;
        return Vector2D();
    }

    Vector2D operator-() const {
        // TODO: Implement unary negation (-x, -y)
        return Vector2D();
    }

    double dot(const Vector2D& rhs) const {
        // TODO: Implement dot product (x1*x2 + y1*y2)
        (void)rhs;
        return 0.0;
    }

    double magnitude() const {
        // TODO: Return Euclidean norm: sqrt(x_*x_ + y_*y_)
        return 0.0;
    }

    bool operator==(const Vector2D& rhs) const {
        // TODO: Return true if |x1 - x2| < 1e-6 and |y1 - y2| < 1e-6
        (void)rhs;
        return false;
    }

    bool operator!=(const Vector2D& rhs) const {
        return !(*this == rhs);
    }

    string toString() const {
        ostringstream oss;
        oss << "(" << fixed << setprecision(1) << x_ << ", " << y_ << ")";
        return oss.str();
    }

private:
    double x_;
    double y_;
};

// Commutative scalar multiplication: scalar * v
inline Vector2D operator*(double scalar, const Vector2D& v) {
    // TODO: delegate to v * scalar
    return v * scalar;
}
