#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

Rectangle::~Rectangle(){}

double Rectangle::area() const{
    return width * height;
}

void Rectangle::draw() const{
    std::cout << "Drawing a Rectangle (" << width << "x" << height << ")" << std::endl;
}