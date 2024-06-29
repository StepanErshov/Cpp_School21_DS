#ifndef TRIANGLEPYRAMID_H
#define TRIANGLEPYRAMID_H

#include "Shape3D.h"
#include "Triangle.h"

class TrianglePyramid : public Shape3D {
private:
    Triangle baseTriangle;
    float pyramidHeight; // Renamed for clarity

public:
    explicit TrianglePyramid(float base, float height)
        : baseTriangle(base, height), pyramidHeight(height) {
        CalculateVolume();
    }

    void CalculateVolume() override {
        baseTriangle.CalculateArea();
        SetVolume((1.0f / 3.0f) * baseTriangle.GetArea() * pyramidHeight);
    }

    void Scale(float scaleFactor) override {
        baseTriangle.Scale(scaleFactor);
        pyramidHeight *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() override {
        std::cout << "Triangle Pyramid with base " << baseTriangle.GetArea()
                 << " and height " << pyramidHeight << " has volume " << GetVolume()
                 << std::endl;
    }

    std::string GetName() override {
        return "Triangle Pyramid";
    }
};

#endif // TRIANGLEPYRAMID_H
