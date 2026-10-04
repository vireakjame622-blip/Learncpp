#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

// ============================================================================
// 🚀 RUN COMMAND (To test your code, run in Terminal):
//    python cpp_exercises/test_runner.py 03_inheritance_polymorphism
//    OR:
//    .\run_tests.bat 03_inheritance_polymorphism
// ============================================================================

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// EXERCISE 5.3: Abstract Classes & Runtime Polymorphism
// CADT Advanced Algorithm & C++ • Week 3 OOP
//
// TASKS:
// 1. Abstract Base Class Shape:
//    - Pure virtual functions: double area() const = 0, double perimeter() const = 0, string name() const = 0.
//    - Virtual destructor: virtual ~Shape() = default.
// 2. Concrete Derived Class Circle:
//    - Radius validation: throw invalid_argument if radius <= 0.
//    - Override area() = M_PI * r^2, perimeter() = 2 * M_PI * r, name() = "Circle".
// 3. Concrete Derived Class RectangleShape:
//    - Width/height validation: throw invalid_argument if width <= 0 or height <= 0.
//    - Override area() = w * h, perimeter() = 2 * (w + h), name() = "Rectangle".
// 4. Polymorphic Helper:
//    - double computeTotalArea(const vector<const Shape*>& shapes)

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string name() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {
        // TODO: Validate radius > 0, throw invalid_argument if <= 0
    }

    double area() const override {
        // TODO: Return circle area: M_PI * radius_ * radius_
        return 0.0;
    }

    double perimeter() const override {
        // TODO: Return circumference: 2.0 * M_PI * radius_
        return 0.0;
    }

    string name() const override {
        return "Circle";
    }

    double radius() const { return radius_; }

private:
    double radius_{0.0};
};

class RectangleShape : public Shape {
public:
    RectangleShape(double width, double height) : width_(width), height_(height) {
        // TODO: Validate width > 0 and height > 0, throw invalid_argument if <= 0
    }

    double area() const override {
        // TODO: Return rectangle area: width_ * height_
        return 0.0;
    }

    double perimeter() const override {
        // TODO: Return perimeter: 2.0 * (width_ + height_)
        return 0.0;
    }

    string name() const override {
        return "Rectangle";
    }

    double width() const { return width_; }
    double height() const { return height_; }

private:
    double width_{0.0};
    double height_{0.0};
};

inline double computeTotalArea(const vector<const Shape*>& shapes) {
    // TODO: Iterate over shapes and accumulate s->area() polymorphically
    (void)shapes;
    return 0.0;
}
