#ifndef ISHAPE_H
#define ISHAPE_H

class IShape
{
public:
    virtual ~IShape() {}    // 가상 소멸자: 올바른 메모리 해제를 위해 필요
    virtual double area() const = 0;    // 각 도형의 면적 계산 함수 (순수 가상 함수)
    virtual void draw() const = 0;      // 도형을 출력(혹은 그리기) 위한 함수 (순수 가상 함수)
};


#endif