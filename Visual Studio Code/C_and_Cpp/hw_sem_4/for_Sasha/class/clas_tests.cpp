#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "TrianglePyramid.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Shpere.h"

void testSquare() {
    std::cout << "Testing Square...\n";
    Square square(5);
    square.ShowInfo();
    square.Scale(2);
    square.ShowInfo();
    std::cout << "Square test complete.\n";
}

void testTriangle() {
    std::cout << "Testing Triangle...\n";
    Triangle triangle(5, 10);
    triangle.ShowInfo();
    triangle.Scale(2);
    triangle.ShowInfo();
    std::cout << "Triangle test complete.\n";
}

void testTrianglePyramid() {
    std::cout << "Testing Triangular Pyramid...\n";
    TrianglePyramid pyramid(5, 10);
    pyramid.ShowInfo();
    pyramid.Scale(2);
    pyramid.ShowInfo();
    std::cout << "Triangular Pyramid test complete.\n";
}

void testCircle() {
    std::cout << "Testing Circle...\n";
    Circle circle(5);
    circle.ShowInfo();
    circle.Scale(2);
    circle.ShowInfo();
    std::cout << "Circle test complete.\n";
}

void testCylinder() {
    std::cout << "Testing Cylinder...\n";
    Cylinder cylinder(5, 10);
    cylinder.ShowInfo();
    cylinder.Scale(2);
    cylinder.ShowInfo();
    std::cout << "Cylinder test complete.\n";
}

void testSphere() {
    std::cout << "Testing Sphere...\n";
    Sphere sphere(5);
    sphere.ShowInfo();
    sphere.Scale(2);
    sphere.ShowInfo();
    std::cout << "Sphere test complete.\n";
}

int main() {
    testSquare();
    testTriangle();
    testTrianglePyramid();
    testCircle();
    testCylinder();
    testSphere();

    std::cout << "All tests complete.\n";
    return 0;
}
