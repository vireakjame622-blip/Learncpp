#pragma once
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

// Verified Solution for Exercise 5.2: Operator Overloading
class Vector2D {
public:
    Vector2D() : x_(0.0), y_(0.0) {}
    Vector2D(double x, double y) : x_(x), y_(y) {}

    double x() const { return x_; }
    double y() const { return y_; }

    Vector2D operator+(const Vector2D& rhs) const {
        return Vector2D(x_ + rhs.x_, y_ + rhs.y_);
    }

    Vector2D operator-(const Vector2D& rhs) const {
        return Vector2D(x_ - rhs.x_, y_ - rhs.y_);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x_ * scalar, y_ * scalar);
    }

    Vector2D operator-() const {
        return Vector2D(-x_, -y_);
    }

    double dot(const Vector2D& rhs) const {
        return x_ * rhs.x_ + y_ * rhs.y_;
    }

    double magnitude() const {
        return sqrt(x_ * x_ + y_ * y_);
    }

    bool operator==(const Vector2D& rhs) const {
        return abs(x_ - rhs.x_) < 1e-6 && abs(y_ - rhs.y_) < 1e-6;
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

inline Vector2D operator*(double scalar, const Vector2D& v) {
    return v * scalar;
}
