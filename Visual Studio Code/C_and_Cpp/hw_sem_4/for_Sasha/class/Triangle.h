#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape2D.h"

class Triangle : public Shape2D {
private:
    float triangleBase; // Renamed for clarity
    float triangleHeight; // Renamed for clarity

public:
    explicit Triangle(float base, float height) : triangleBase(base), triangleHeight(height) {} // Use explicit keyword for constructor

    void CalculateArea() override { SetArea(0.5 * triangleBase * triangleHeight); }

    void Scale(float scaleFactor) override {
        triangleBase *= scaleFactor;
        triangleHeight *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override {
        std::cout << "Triangle with base " << triangleBase << " and height " << triangleHeight
                 << " has area " << GetArea() << std::endl;
    }

    std::string GetName() override {
        return "Triangle";
    }
};

#endif // TRIANGLE_H
