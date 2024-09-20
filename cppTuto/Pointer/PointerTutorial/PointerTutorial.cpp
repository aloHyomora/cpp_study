#include <iostream>

using namespace std;

void AddHp(int* hp, int value) {
	*hp += value;
}

int main() {
	int hp = 100;

	// [타입]* [이름]
	// 주소값을 담는 바구니, 64비트 운영체제면 이 변수는 8바이트짜리 값
	void* ptr = &hp; // hp 변수의 주소를 넣음. 
	int* ptrInt = &hp; // hp 변수의 주소를 넣음., ptrInt에 가면 int 값이 들어있음. 
	// float* ptrFloat = (float*)&hp; // float* 타입으로 형 변환
	// *ptrFloat = 3.14f;

	// (*ptr) -> 주소를 타고감.

	cout << *ptrInt << endl;
	*ptrInt = 300;
	cout << *ptrInt << endl;
	
	cout << endl;

	AddHp(&hp, 100); // 주소값을 복사해서 전달함.
	cout << *ptrInt << endl;	
}