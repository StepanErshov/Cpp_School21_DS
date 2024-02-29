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

  void GetVolume() { return; };
  bool operator>(const Shape3D &other) { return volume > other.volume; };
  bool operator<(const Shape3D &other) { return volume < other.volume; };
  bool operator==(const Shape3D &other) { return volume == other.volume; };
};

class Square : public Shape2D {
private:
  float side;

public:
  Square(float side) : side(side) {}

  void CalculateArea() override { area = side * side; }
};

class Triangle : public Shape2D {
private:
  float base;
  float height;

public:
  Triangle(float base, float height) : base(base), height(height) {}

  void CalculateArea() override { area = 0.5 * base * height; }
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
    volume = (1.0f / 3.0f) * baseTriangle.GetArea() * height;
 }
};

class Circle : public Shape2D {
private:
  float radius;

public:
  Circle(float radius) : radius(radius) {}

  void CalculateArea() override { area = 3.14159f * pow(radius, 2); }
};

class Cylinder : public Shape3D {
private:
  Circle baseCircle;
  float height;

public:
  Cylinder(float radius, float height) : baseCircle(radius), height(height) {}

  void CalculateVolume() override {
    baseCircle.CalculateArea();
    volume = baseCircle.GetArea() * height;
  }
};

class Sphere : public Shape3D {
private:
  float radius;

public:
  Sphere(float radius) : radius(radius) {}

  void CalculateVolume() override {

    volume = (4 * 3.14159f * pow(radius, 3)) / 3;
  }
};

#endif