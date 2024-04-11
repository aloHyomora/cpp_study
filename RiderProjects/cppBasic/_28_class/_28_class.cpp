#include <iostream>
#include "Stock.h"

int main(int argc, char* argv[])
{
    // 추상화와 클래스
    // 데이터형이란 무엇인가?
    // 데이터형을 대상으로 어떠한 연산을 수행할 수 있는가?

    int a = 3;
    int b = 3;
    cout << sizeof(a) << "Byte" << endl; // 4Byte
    
    int* a_p_ = &a;
    int* b_p = &b;
    cout << sizeof(a_p_) << "Byte" << endl; // 8Byte => 포인터의 크기 (64비트 시스템)


    // 클래스란?
    // 추상화를 사용자 정의 데이터형으로 변환해주는 수단

    // 추상화란?
    // 어떠한 객체를 사실적으로 표현하는 것이 아니라, 공통된 특징을 간결한 방식으로 이해하기 쉽게 표현하는 것

    /*
     * 1. 클래스 선언
     * 2. 클래스 메서드 정의
     */

    Stock temp;
    temp.acquire("Panda", 100, 1000);
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();
    
    return 0;
}
