#ifndef EX1
#define EX1
#include <cmath>
#include <iostream>
#include <string>

class Shape {
public:
  virtual void Scale(float scaleFactor) = 0;
  virtual void ShowInfo() = 0;
  virtual std::string GetName() = 0;
};

class Shape2D : public Shape {
private:
  float area = 0;
  void virtual CalculateArea() = 0;

public:
  Shape2D() { CalculateArea(); }

  float GetArea() { return area; };
  void SetArea(float a) {
    if (a > 0) {
      area = a;
    } else {
      throw std::runtime_error("ERROR 300");
    }
  }
  bool operator>(const Shape2D &other) { return area > other.area; };
  bool operator<(const Shape2D &other) { return area < other.area; };
  bool operator==(const Shape2D &other) { return area == other.area; };
};

class Shape3D : public Shape {
private:
  float volume = 0;
  void virtual CalculateVolume() = 0;

public:
  Shape3D() { CalculateVolume(); }

  float GetVolume() { return volume; };
  void SetVolume(float v) {
    if (v > 0) {
      volume = v;
    } else {
      throw std::runtime_error("ERROR 300");
    }
  }
  bool operator>(const Shape3D &other) { return volume > other.volume; };
  bool operator<(const Shape3D &other) { return volume < other.volume; };
  bool operator==(const Shape3D &other) { return volume == other.volume; };
};

class Square : public Shape2D {
private:
  float side;

public:
  Square(float side) : side(side) {}

  void CalculateArea() override { SetArea(side * side); }

  void Scale(float scaleFactor) override {
    side *= scaleFactor;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "Square with side " << side << " has area " << GetArea()
              << std::endl;
  }

  std::string GetName() override { return "Square"; }
};

class Triangle : public Shape2D {
private:
  float base;
  float height;

public:
  Triangle(float base, float height) : base(base), height(height) {}

  void CalculateArea() override { SetArea(0.5 * base * height); }

  void Scale(float scaleFactor) override {
    base *= scaleFactor;
    height *= scaleFactor;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "Triangle with base " << base << " and height " << height
              << " has area " << GetArea() << std::endl;
  }

  std::string GetName() override { return "Triangle"; }
};

class TriangularPyramid : public Shape3D {
private:
  Triangle baseTriangle;
  float height;

public:
  TriangularPyramid(float base, float height)
      : baseTriangle(base, height), height(height) {}

  void CalculateVolume() override {
    baseTriangle.CalculateArea();
    SetVolume((1.0f / 3.0f) * baseTriangle.GetArea() * height);
  }

  void Scale(float scaleFactor) override {
    baseTriangle.Scale(scaleFactor);
    height *= scaleFactor;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "Triangular Pyramid with base " << baseTriangle.GetArea()
              << " and height " << height << " has volume " << GetVolume()
              << std::endl;
  }

  std::string GetName() override { return "Triangular Pyramid"; }
};

class Circle : public Shape2D {
private:
  float radius;

public:
  Circle(float radius) : radius(radius) {}

  void CalculateArea() override { SetArea(3.14159f * pow(radius, 2)); }

  void Scale(float scaleFactor) override {
    radius *= scaleFactor;
    CalculateArea();
  }

  void ShowInfo() override {
    std::cout << "Circle with radius " << radius << " has area " << GetArea()
              << std::endl;
  }

  std::string GetName() override { return "Circle"; }
};

class Cylinder : public Shape3D {
private:
  Circle baseCircle;
  float height;

public:
  Cylinder(float radius, float height) : baseCircle(radius), height(height) {}

  void CalculateVolume() override {
    baseCircle.CalculateArea();
    SetVolume(baseCircle.GetArea() * height);
  }

  void Scale(float scaleFactor) override {
    baseCircle.Scale(scaleFactor);
    height *= scaleFactor;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "Cylinder with radius " << baseCircle.GetArea()
              << " and height " << height << " has volume " << GetVolume()
              << std::endl;
  }

  std::string GetName() override { return "Cylinder"; }
};

class Sphere : public Shape3D {
private:
  float radius;

public:
  Sphere(float radius) : radius(radius) {}

  void CalculateVolume() override {

    SetVolume((4 * 3.14159f * pow(radius, 3)) / 3);
  }
  void Scale(float scaleFactor) override {
    radius *= scaleFactor;
    CalculateVolume();
  }

  void ShowInfo() override {
    std::cout << "Sphere with radius " << radius << " has volume "
              << GetVolume() << std::endl;
  }

  std::string GetName() override { return "Sphere"; }
};

#endif