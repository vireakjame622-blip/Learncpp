#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Verified Solution for Exercise 5.3: Inheritance & Polymorphism
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
        if (radius <= 0) throw invalid_argument("Radius must be positive");
    }

    double area() const override {
        return M_PI * radius_ * radius_;
    }

    double perimeter() const override {
        return 2.0 * M_PI * radius_;
    }

    string name() const override {
        return "Circle";
    }

    double radius() const { return radius_; }

private:
    double radius_;
};

class RectangleShape : public Shape {
public:
    RectangleShape(double width, double height) : width_(width), height_(height) {
        if (width <= 0 || height <= 0) throw invalid_argument("Dimensions must be positive");
    }

    double area() const override {
        return width_ * height_;
    }

    double perimeter() const override {
        return 2.0 * (width_ + height_);
    }

    string name() const override {
        return "Rectangle";
    }

    double width() const { return width_; }
    double height() const { return height_; }

private:
    double width_;
    double height_;
};

inline double computeTotalArea(const vector<const Shape*>& shapes) {
    double total = 0.0;
    for (const Shape* s : shapes) {
        if (s) total += s->area();
    }
    return total;
}
