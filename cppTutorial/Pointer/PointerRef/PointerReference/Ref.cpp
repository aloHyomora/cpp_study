#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int deffence;
};
 
// 1) ��(����) ���� ���
void PrintByCopy(StatInfo player) {
	cout << "--------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "Atk : " << player.attack << endl;
	cout << "Def : " << player.deffence << endl;
	cout << "--------------------------" << endl;
}

// 2) �ּ� ���� ��� -> 1) ������ �ǵ帮�� ���� ��, 2) ���� ����� �Ƴ��� ���� ��
void PrintByPointer(StatInfo* player) {
	cout << "--------------------------" << endl;
	cout << "HP : " << (*player).hp << endl;
	cout << "Atk : " << player->attack << endl;
	cout << "Def : " << player->deffence << endl;
	cout << "--------------------------" << endl;
}

// 3) ���� ���� ���
#define OUT // ->> OUT ���� �����͸� �����ϰڴ�~ ������ OUT �ڰ� ��� �־ �ǹ̰� ����.

void PrintByRef(OUT StatInfo& player) { // void PrintByRef(const StatInfo& player) -> ���� ������ �������� �ʰ� ���� (����� �Ƴ��� ���� ���� ���)
	cout << "--------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "Atk : " << player.attack << endl;
	cout << "Def : " << player.deffence << endl;
	cout << "--------------------------" << endl;
}

int main() {
	StatInfo player = { 100, 10, 1 };
	
	PrintByCopy(player);
	PrintByPointer(&player);

	StatInfo* ptr = nullptr;


	StatInfo* info = &player;
	
	StatInfo& ref = player; // �ּ� ���� �̿��ؼ� ������ �ǵ帰��. player�� ref��� ��Ī�� ���δ�.
	// ������ ���� ������ ���������� ����� �Ϲ� ����ó�� ����.
	// ref.hp = 10;
	PrintByRef(OUT player);
}