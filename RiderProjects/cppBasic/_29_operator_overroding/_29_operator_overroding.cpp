#include <iostream>
#include "Time.h"
using namespace std;

int main(int argc, char* argv[])
{
	// << 연산자 오버로딩
	Time t5(3,45);

	// 출력할 때 t1.show()가 아니라 cout << t1으로만 하고 싶다.
	cout << t5 << endl;
	
	cout << "===============================" << endl;

	// C++ friend
	// class에서 private 부분의 멤버 변수에 접근 가능하게 함.
	// 이항연산자 : 두 개의 피연산자를 요구하는 연산자

	// 연산자 오버로딩 : Time 객체 간의 연산을 가능하게 함.
	// 타임 객체와 int형 변수의 곱을 하려고 하면 에러, 이를 해결해준다.

	Time t1(1, 20);
	Time t2;

	t2 = 3 * t1;
	t2.show();

	Time t3;
	t3 = t1 * 4;
	t3.show();
	
	cout << "===============================" << endl;
    // 연산자 오버로딩
    // 연산자 오버로딩을 사용자 정의에 확장한다.
    Time day1(1, 40);
    Time day2(2, 30);

    day1.show();
    day2.show();

    Time total;
    // total = day1.sum(day2);
    total.show();

     // Total = day1 + day2 처럼  구현하고 싶다.
    Time total1;
	total1 = day1.operator+(day2);

	Time total2;
	total2 = day1 + day2;

	total1.show();
	total2.show();
	
    return 0;
}
