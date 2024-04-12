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

	// default 생성자를 통해 크기가 4인 Stock 생성
	// Stock s[4];

	// Stock 타입으로 배열을 생성하고 각각의 원소에 대입하는 것이기 때문에,
	// default constructor(생성자)가 필요하다.
	Stock s[4] = {
		Stock("A", 10 , 1000),
		Stock("B", 10 , 1200),
		Stock("C", 10 , 1300),
		Stock("D", 10 , 1400)
	};

	s[0].show();
	
	cout << "======================" << endl;
	
    Stock temp = Stock("Panda", 100, 1000);
	Stock temp2 = Stock("Panda2", 200, 2000);
	Stock temp3;

	temp.show();
	temp2.show();

	cout << "Bigger value : ";
	temp.getTopVal(temp2).show();
	temp2.getTopVal(temp).show();
	
	/*temp = Stock("new Panda", 1000, 3000);
	temp.show();*/

	
	// 생성자가 정의되지 않아도 정상적으로 작동한다.
	// C++에서 암시적으로 디폴트 생성자를 지원해주기 때문.
	
    // temp.acquire("Panda", 100, 1000);
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();
    
    return 0;
}
