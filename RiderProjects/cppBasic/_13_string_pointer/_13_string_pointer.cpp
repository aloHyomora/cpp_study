#include <iostream>

#define SIZE 20
#pragma warning(disable:4996)
using namespace std;

int main(int argc, char* argv[])
{
	char animal[SIZE];
	char* ps;

	cout << "Write animal name\n";
	cin >> animal;

	ps = new char[strlen(animal) + 1]; // 공간 할당 ( + 1 : null 문자 )
	strcpy(ps, animal);				   // 입력받은 animal을 ps에 복사
	// strlen : animal의 크기를 반환하는 메서드
	// strcpy : parm2를 parm1로 복사하는 메서드
	
	cout << "copied animal name you wrote." << endl;
	cout << "Animal name you wrote is " << animal << ", Address is "<< (int*)animal <<endl;
	cout << "copied animal name " << ps <<", Address is " << (int*)ps << endl;
	
	return 0;
}
