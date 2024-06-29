#ifndef SPHERE_H
#define SPHERE_H
#include "Shape3D.h"
#include <cmath> // Include cmath for pow and M_PI

class Sphere : public Shape3D {
private:
    float sphereRadius; // Renamed for clarity
    static constexpr float PI = 3.14159f; // Define PI as a constant
    static constexpr float FOUR_THIRDS = 4.0f / 3.0f; // Define 4/3 as a constant

public:
    explicit Sphere(float radius) : sphereRadius(radius) {} // Use explicit keyword for constructor

    void CalculateVolume() override {
        SetVolume(FOUR_THIRDS * PI * pow(sphereRadius, 3)); // Use PI and FOUR_THIRDS constants
    }

    void Scale(float scaleFactor) override {
        sphereRadius *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() override {
        std::cout << "Sphere with radius " << sphereRadius << " has volume "
                 << GetVolume() << std::endl;
    }

    std::string GetName() override {
        return "Sphere";
    }
};

#endif // SPHERE_H
