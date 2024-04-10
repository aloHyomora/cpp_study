#include <iostream>

using namespace std;

const float Pi = 3.14; // 상수 선언
void Cheers(int n);    // 함수 원형
float Circle(int x);
int main(int argc, char* argv[])
{
    /*
     * 1. 함수 정의 제공
     * 2. 함수 원형 제공
     * 3. 함수 호출
     */

	/*
	 * 1. 리턴값이 있는 타입
	 * typeName functionName(parameterList)
	 * {
	 *		statement(s)
	 *		return value;
	 * }
	 * 2. 리턴값이 없는 타입
	 * void functionName(parameterListr)
	 * {
	 *		statement(s);
	 *		return; // 생략 가능
	 * }
	 */
	int a;
	cout << "Write num." << endl;
	cin >> a;
	Cheers(a);

	int b;
	cout << "Write radius of circle " << endl;
	cin >> b;
	float area = Circle(b);
	cout << "Area of Circle " << area << ".\n";
	
    return 0;
}
void Cheers(int n) // 함수 정의
{
	for (int i = 0; i < n; i++)
	{
		cout << "Cheers!" <<endl;
	}
}
float Circle(int x)
{
	return x * x * Pi;
}