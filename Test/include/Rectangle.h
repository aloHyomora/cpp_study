#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape {
public:
    Rectangle(double w, double h);  // 가로와 세로를 초기화하는 생성자
    virtual ~Rectangle();

    virtual double area() const override;  // 면적 계산 함수
    virtual void draw() const override;      // 도형 출력 함수

private:
    double width;
    double height;
};

#endif // RECTANGLE_H
