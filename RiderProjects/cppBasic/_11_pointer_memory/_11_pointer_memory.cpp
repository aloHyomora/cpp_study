#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int val = 3;
    cout << &val << endl;

    // C++ : Object Oriented Programing
    /*
     *컴파일 중이 아닌 실행 중에 결정을 내릴 수 있다.
     * 재래적 절차적 프로그래밍 : 배열의 크기가 미리 결정
     * 객체지향 프로그래밍 : 배열의 크기를 실행 중에 결정
     */

	// pointer : naming Address to use
	// 즉, 포인터는 포인터의 이름이 주소를 나타낸다.
	// 간접값 연산자, 간접 참조 연산자 *

	int *a; // c style
	int* b; // c++ style
	int* c, d; // c : pointer vairable, d : normal int variable

	int num = 6;
	int* k;

	k= &num;

	cout << "value num : " << num << endl;
	cout << "value *k : " << *k << endl;
	
	cout << "address num : " << &num << endl;
	cout << "address *k : " << k << endl;

	*k = *k + 1;

	cout << "*k = *k + 1 => value num " << num << endl;

	// While executing a program, memory that has not yet been determined, can be assigned.
	// that's pointer
	
    return 0;
}
