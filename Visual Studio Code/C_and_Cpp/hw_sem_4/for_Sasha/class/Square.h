#ifndef SQUARE_H
#define SQUARE_H

#include "Shape2D.h"

class Square : public Shape2D {
private:
    float squareSide; // Renamed for clarity

public:
    explicit Square(float side) : squareSide(side) { CalculateArea(); } // Use explicit keyword for constructor

    void CalculateArea() override { SetArea(squareSide * squareSide); }

    void Scale(float scaleFactor) override {
        squareSide *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override {
        std::cout << "Square with side " << squareSide << " has area " << GetArea()
                 << std::endl;
    }

    std::string GetName() override {
        return "Square";
    }
};

#endif // SQUARE_H
