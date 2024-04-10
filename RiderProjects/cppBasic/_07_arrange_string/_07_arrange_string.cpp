#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
    /*
     * array(배열) : Set of same data type
     * typeName arrayName[arraySize];
     */
	short month[12] = {1, 2, 3}; // declare

	cout << month << endl;

	/*
	 * 배열 규칙
	 * 배열 원소에 대입할 값들을 콤마로 구분하여 중괄호로 묶어 선언한다.
	 * 배열 선언 이후 초기화를 나중에 할 수 없다.
	 * 배열을 다른 배열에 통째로 대입할 수 없다.
	 * 배열 원소의 개수보다 모자라게 초기화를 할 수 있다.
	 * 배열을 부분적으로 초기화할 경우, 나머지 원소들은 모두 0으로 설정된다.
	 * 명시적으로 첫 번째 원소만 0으로 초기화하면, 나머지 원소들은 모두 0으로 초기화된다.
	 * 배열을 초기화할 때 대괄호 속을 비워두면 컴파일러가 값이 개수를 헤아려 배열 원소 개수를 저장한다. // short month[] = {1, 2, 3}; 크기 3으로 초기화
	 */

	char a[] = {'H', 'e', 'l', 'l','o','\0'};
	char b[] = "Hello (b)";
	cout << a << endl;
	cout << b << endl;
    return 0;
}
