// dynamic arrangement.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Array.h"
#include "Vector.h"

int main()
{
    /*Array arr(100);

    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PushBack(4);
    arr.PushBack(5);

    arr[1] = 2;

    int b = arr[1000];*/

    Vector v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);

    int a = v[1];

    std::cout << "Hello World!\n";
}
