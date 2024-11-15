#include <iostream>
using namespace std;


// OOP 3�� ���
// - ��Ӽ� << inheritance (�����޴´�..)
// - ���м� << data hiding (Encapsulization)
// - ������ << Polymorphism

// �����ε� vs �������̵�
// �����ε� = �Լ� �̸��� ����
void Test() {}
void Test(float a) {}
void Test(bool b) {}


// �������̵� = �ڽ� Ŭ���� ����� �������ϱ�
// VF table virtual function table
// VF Table [�ּ�1][�ּ�2][�ּ�3] <- virtual �޼��带 ����ϸ� ���� ������ ù ��°�� VF Table�� �����ȴ�.
class Player {
public:
	virtual void Move() { cout << "Player Move()!" << endl; } // virtual -> ���� ������ �����ƴ�. Move�� ���� Ÿ���� ã�ư���..
	virtual ~Player(){} // Knight �����͸� ������ �Ϸ��� �ݵ�� �θ� Ŭ������ �Ҹ��ڿ� virtual Ű���带 �ٿ��� �Ѵ�.
public:
	int m_hp;
};
// ���� ���� �Լ� virtual void Move() = 0; �����δ� ���� �ڽ� ��ü���� �ۼ��ؾ� ��.
// ���� ���� �Լ��� ����� ��� �߻� Ŭ������� Ī�ϸ� Move�� ���� ������ �����ؾ� �Ѵ�. (�������̽� ����~?)

class Knight : public Player {
public:
	virtual void Move() override { cout << "Knight Move()!" << endl; } // �ڽ� Ŭ������ virtual ~~() override �������̵� Ű���带 �ݵ�� ������! ����üũ�뵵

public:
	int m_stamina;
};

// ���ε�(Binding) = ���´�.
// ���� ���ε�(static binding) = ������ ���� ����
// ���� ���ε�(dynamic binding) = ���� ���� ����
void MovePlayer(Player* player) {
	player->Move();
}
int main() {
	Knight k1;
	k1.Move();
	MovePlayer(&k1);
}