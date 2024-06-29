#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape2D.h"
#include <cmath> // Include cmath for pow and M_PI

class Circle : public Shape2D {
private:
    float radius;
    static constexpr float PI = 3.14159f; // Define PI as a constant

public:
    explicit Circle(float radius) : radius(radius) {} // Use explicit keyword for constructor

    void CalculateArea() override {
        SetArea(PI * pow(radius, 2)); // Use PI constant
    }

    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override {
        std::cout << "Circle with radius " << radius << " has area " << GetArea() << std::endl;
    }

    std::string GetName() override {
        return "Circle";
    }
};

#endif // CIRCLE_H
