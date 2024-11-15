#include <iostream>

using namespace std;

void Swap(int* a, int* b) // �ּ�
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
struct StatInfo {
	int hp;
	int attack;
	int deffence;
};
StatInfo CreatePlayer() {
	StatInfo info;

	cout << "�÷��̾� ����" << endl;

	info.hp = 100;
	info.attack = 20;
	info.deffence = 10;

	return info;

	// �����ϴ� ������� ����. -> ���� �����Ͱ� �Ѽյŵ� ������ ����.
	// StatInfo�� ũ�Ⱑ ��û Ŀ���ٸ�? -> ����� �����ϴ� ������ �ָ�.

}

void CreateMonster(StatInfo* info) { // �����Ͱ� �ƴ϶� StatInfo�� �ѱ��? �����ؼ� �ѱ�� ����̾�. �δ㽺����?
	cout << "���� ����" << endl;

	info->hp = 40;
	info->attack = 8;
	info->deffence = 4;
}
void Battle(StatInfo* playerPtr, StatInfo* monsterPtr) {
	while (true)
	{
		// ������ ���(����)
		int damage = playerPtr->attack - monsterPtr->deffence;
		if (damage < 0) damage = 0;

		monsterPtr->hp -= damage;
		if (monsterPtr->hp < 0) monsterPtr->hp = 0;

		cout << "���� HP : " << monsterPtr->hp << endl;

		if (monsterPtr->hp == 0) return;

		// ������ ���(�÷��̾�)
		damage = monsterPtr->attack - playerPtr->deffence;
		if (damage < 0) damage = 0;

		playerPtr->hp -= damage;
		if (playerPtr->hp < 0) playerPtr->hp = 0;

		cout << "�÷��̾� HP : " << playerPtr->hp << endl;

		if (playerPtr->hp == 0) return;
	}
}
int main() {
	StatInfo player; // ���� ������ ����
	player = CreatePlayer();

	StatInfo monster;
	CreateMonster(&monster);

	Battle(&player, &monster);

	cout << endl; 
	cout << endl;
	// ������ ����
	// �ּ� ������ &
	// ��� ������ + -
	// ���� ������ *
	// ���� ��� ������ ->

	// ============== �ּ� ������ & ==========================
	int numbers[100] = { 1,2,3,4,5,6 };
	int* ptr = &numbers[0]; // &numbers
	*(ptr + 3) = 666; // int�� 4����Ʈ ũ�� ��ŭ �ּҸ� 3ĭ �ű� = 0�� �ε��� + 3 = 3�� �ε���

	// *ptr == numbers[0]
	// *(ptr+3) == numbers[3]


	// =============== ���� ������, ���� ��� ������ -> =========================
	StatInfo monster;
	monster.hp = 100;
	monster.attack = 10;
	monster.deffence = 2;

	StatInfo* ptrMonster = &monster;

	cout << (*ptrMonster).hp << endl; // cout << ptrMonster->hp << endl

}
	//void* ptr = nullptr; // � ������ �ּҸ� ������ �ִ� �ٱ���

	//int a = 10;
	//int b = 20;

	//cout << "a : " << a << " b : " << b << endl;
	//Swap(&a, &b);

	//int* ptra = &a;
	//*ptra = 30;

	//cout << "a : " << a << " b : " << b << endl;


//	int hp = 100;
//
//	// [Ÿ��]* [�̸�]
//	// �ּҰ��� ��� �ٱ���, 64��Ʈ �ü���� �� ������ 8����Ʈ¥�� ��
//	void* ptr = &hp; // hp ������ �ּҸ� ����. 
//	int* ptrInt = &hp; // hp ������ �ּҸ� ����., ptrInt�� ���� int ���� �������. 
//	// float* ptrFloat = (float*)&hp; // float* Ÿ������ �� ��ȯ
//	// *ptrFloat = 3.14f;
//
//	// (*ptr) -> �ּҸ� Ÿ��.
//
//	cout << *ptrInt << endl;
//	*ptrInt = 300;
//	cout << *ptrInt << endl;
//	
//	cout << endl;
//
//	AddHp(&hp, 100); // �ּҰ��� �����ؼ� ������.
//	cout << *ptrInt << endl;	
//}