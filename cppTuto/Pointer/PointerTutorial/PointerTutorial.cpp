#include <iostream>

using namespace std;

void AddHp(int* hp, int value) {
	*hp += value;
}

int main() {
	int hp = 100;

	// [Ÿ��]* [�̸�]
	// �ּҰ��� ��� �ٱ���, 64��Ʈ �ü���� �� ������ 8����Ʈ¥�� ��
	void* ptr = &hp; // hp ������ �ּҸ� ����. 
	int* ptrInt = &hp; // hp ������ �ּҸ� ����., ptrInt�� ���� int ���� �������. 
	// float* ptrFloat = (float*)&hp; // float* Ÿ������ �� ��ȯ
	// *ptrFloat = 3.14f;

	// (*ptr) -> �ּҸ� Ÿ��.

	cout << *ptrInt << endl;
	*ptrInt = 300;
	cout << *ptrInt << endl;
	
	cout << endl;

	AddHp(&hp, 100); // �ּҰ��� �����ؼ� ������.
	cout << *ptrInt << endl;	
}