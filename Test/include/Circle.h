#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

class Circle : public IShape {
public:
    explicit Circle(double r);   // 반지름을 초기화하는 생성자
    virtual ~Circle();           // 소멸자 선언

    virtual double area() const override;  // 면적 계산 함수
    virtual void draw() const override;      // 도형 출력 함수

private:
    double radius;
};

#endif // CIRCLE_H
