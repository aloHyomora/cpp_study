#include <iostream>

using namespace std;


// OOP 3�� ���
// - ��Ӽ� << inheritance (�����޴´�..)
// - ���м� << data hiding (Encapsulation)
// - ������

// ���赵

// Is-A vs Has-A
// Is-A ��Ӽ�

class Player {
public:
	void Move() {}
	void Attack() {}
	void Die() {}

public:
	// PlayerType m_type;
	int m_hp;
	int m_attack;
	int m_defence;
};
enum PLAYER_TYPE {
	Knight = 1,
	Archer = 2,
	Magician = 3,
};
class Knight : public Player{ 
public:

public:
};

class Archer : public Player{
public:

public:
	int m_arrowCount;
};

class Magician : public Player{
public:
public:
	int m_mp;
};

void Fight(Player* p1, Player* p2) {


}


int main() {
	// ĳ����(Ÿ�� ��ȯ)
	
	Knight k1;
	Player* p1 = &k1;

	Magician m1;
	Player* p2 = &m1;

}