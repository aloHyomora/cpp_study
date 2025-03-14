#include "Circle.h"
#include <iostream>
constexpr double PI = 3.14159265358979323846;
  // M_PI를 사용하기 위해

Circle::Circle(double r) : radius(r) {}

Circle::~Circle() {}

double Circle::area() const {
    return PI * radius * radius;  // 원의 면적 계산
}

void Circle::draw() const {
    std::cout << "Drawing a Circle with radius: " << radius << std::endl;
}
