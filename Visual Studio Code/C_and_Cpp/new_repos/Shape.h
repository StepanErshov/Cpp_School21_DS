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

#endif