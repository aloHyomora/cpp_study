#include <iostream>
using namespace std;

// ��ü����
// ������ + ����

class Inventory {
public:
	Inventory() {
		cout << "Inventory()" << endl;
	}
	Inventory(int a) {
		cout << "Inventory(int)" << endl;
	}
	~Inventory() {
		cout << "~Inventory()" << endl;
	}
public:
	int m_itemNum = 10;
};

class Player {
public:
	Player() {
		cout << "Player()" << endl;
	}
	~Player() {
		cout << "~Player()" << endl;
	}
public:

};
class Knight : Player{
public: // �������� ������  <class Name>() : @@@(100)
	Knight() : m_hp(0)  // �߰��� int& Ÿ���̳� const int ���� �κ��� �� ����� ����ϴ� �� ����.
	/*
		��ó�� ����
		��� �� �κп��� Player�� �����ڰ� ȣ���. �Ҹ��ڴ� �������� ȣ���. ������ �㹫�� ����
	*/
	{
		cout << "Knight()" << endl;
		m_hp = 0; // �̷��Ե� ��� ���� �ʱ�ȭ ����
		// m_inventory2 = Inventory(100); // �������� �ʱ�ȭ�ϴ� �� �����ϱ�!, ��ȿ������ ����̴�.
	}
	// �����ڳ����� ȣ�� ���� Knight(int hp) : m_hp(hp)�� �⺻ �����ڿ��� �̿��ϴ� ���!
	~Knight() {
		cout << "~Knight()" << endl;
	}
public:
	int m_hp = 0; // �̷��Ե� ��� ���� �ʱ�ȭ ����
	Inventory* m_inventory; // �ּҸ� ������ ����.
	Inventory m_inventory2; // �̷� ����� Knight ������ ������ Inventory ũ�⸸ŭ �Ҵ���� ���·� ������.
};

int main() {
	Knight k1;


}