#include <iostream>
#include "include/Circle.h"
#include "include/Rectangle.h"

int main(){
    // 동적 할당 시 IShape 포인터를 이용하여 다형성을 활용
    IShape* circle = new Circle(5.0);
    IShape* rectangle = new Rectangle(4.0, 6.0);

    circle->draw();
    std::cout << "Circle area: " << circle->area() << std::endl;

    rectangle->draw();
    std::cout << "Rectangle area: " << rectangle->area() << std::endl;
    
    // 메모리 해제
    delete circle;
    delete rectangle;

    return 0;
}