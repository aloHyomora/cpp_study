#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // new
    /*
     * let new operator know data format, new operator finds memory of the appropriate size for it and returns the address of that block.
     * data type에 맞는 메모리 블록을 찾고 그 블록의 주소를 리턴함.     
     */

	// 기존 방식
	int a;
	int* b = &a;
	
	int* pointer = new int; // 4바이트 메모리 블록을 찾아 주소를 pointer 변수에 리턴한다.
	// pointer가 지시하는 메모리의 이름이 없는데 어떻게 메모리에 접근할 수 있을까?
	

	// new를 사용하였다면 반드시 delete를 사용해야 한다.
	/*
	 * delete operator
	 * 사용한 메모리를 다시 메모리 풀로 환수
	 * 환수된 메모리는 프로그램의 다른 부분이 다시 사용
	 */
	int* ps = new int;
	delete ps;
	/*
	 * 1. new로 대입하지 않은 메모리는 delete로 해제할 수 없다.
	 * 2. 같은 메모리 블록을 연달아 두 번 delete로 해제할 수 없다.
	 * 3. new[]로 메모리를 대입할 경우 delete[]로 해제한다.
	 * 4. new로 메모리를 대입할 경우 delete로 해제한다.
	 */

	// double형 데이터 3개를 저장할 수 있는 공간을 대입한다.
	// p3를 배열 이름처럼 취급한다.
	double* p3 = new double[3]; 
	p3[0] = 0.2;				
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1] is " << p3[1] << endl; // p3[1] is 0.5

	p3 = p3 + 1;  
	// 포인터를 증가시킨다.
	// p3 자체가 double형 데이터를 3개 저장할 수 있는 공간에 대한 변수
	// +1은 double형 데이터 공간 1개를 의미한다. 
	// p3에 1을 더한다 = 각 인덱스가 다음 공간을 가리키게 된다.
	
	cout << "Now p3[0] is " << p3[0] << " and "; // Now p3[0] is 0.5 and p3[1] is 0.8
	cout << "p3[1] is " << p3[1] << endl;

	p3 = p3 -1;
	delete[] p3;
	
	
    return 0;
}
