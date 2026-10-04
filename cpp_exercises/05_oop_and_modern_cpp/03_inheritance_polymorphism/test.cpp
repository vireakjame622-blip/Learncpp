#include "exercise.h"
#include "../../include/test_framework.hpp"
#include <memory>
#include <vector>

using namespace std;

int main() {
    TEST_SUITE("03_inheritance_polymorphism (Abstract Interfaces & Virtual Dispatch)");

    // Condition 1: Circle calculations
    {
        Circle c(2.0);
        TEST_EQUAL(c.name(), "Circle", "Circle name is 'Circle'", "Virtual override check");
        TEST_CONDITION(abs(c.area() - (M_PI * 4.0)) < 1e-5, "Circle area with r=2 is 4*pi", "Area calculation");
        TEST_CONDITION(abs(c.perimeter() - (4.0 * M_PI)) < 1e-5, "Circle perimeter is 4*pi", "Perimeter calculation");
        TEST_THROWS(Circle(-1.0), invalid_argument, "Negative radius throws", "Radius validation");
    }

    // Condition 2: RectangleShape calculations
    {
        RectangleShape r(4.0, 5.0);
        TEST_EQUAL(r.name(), "Rectangle", "Rectangle name is 'Rectangle'", "Virtual override check");
        TEST_EQUAL(r.area(), 20.0, "Rectangle 4x5 area is 20", "Area calculation");
        TEST_EQUAL(r.perimeter(), 18.0, "Rectangle 4x5 perimeter is 18", "Perimeter calculation");
        TEST_THROWS(RectangleShape(0.0, 5.0), invalid_argument, "Zero width throws", "Dimension validation");
    }

    // Condition 3: Dynamic Polymorphic Dispatch
    {
        vector<unique_ptr<Shape>> shapes;
        shapes.push_back(make_unique<Circle>(1.0)); // area = pi (~3.14159)
        shapes.push_back(make_unique<RectangleShape>(3.0, 4.0)); // area = 12.0

        vector<const Shape*> rawPointers;
        for (const auto& sp : shapes) rawPointers.push_back(sp.get());

        double total = computeTotalArea(rawPointers);
        double expected = M_PI + 12.0;

        TEST_CONDITION(abs(total - expected) < 1e-5, "Polymorphic computeTotalArea matches sum of sub-shapes", "Virtual dispatch loop");
    }

    TEST_REPORT();
}
