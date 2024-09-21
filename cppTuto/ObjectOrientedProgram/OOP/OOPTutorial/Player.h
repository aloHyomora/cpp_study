#pragma once
#include <iostream>
using namespace std;

// ========= Ŭ���� [���赵] ����� =========  
class Player {
public:
	// �⺻ ������(constructor) ��� ���� �ʱ�ȭ�ض�~
	Player() {
		cout << "Player ����" << endl;
		m_hp = 0;
		m_attack = 0;
		m_defence = 0;
	};

	// ���� ������
	Player(const Player& other) {
		cout << "Player ����(���� ����)" << endl;
		this->m_hp = other.m_hp;
		this->m_attack = other.m_attack;
		this->m_defence = other.m_defence;		
	}

	// ��Ÿ ������
	Player(int hp, int attack, int defence) {
		// ��� ������ �ݵ�� �� �־�� �Ѵٸ� �Ű������� ���� �־� �ʱ�ȭ �ؾ� �Ѵ�.

		cout << "Player ����(��� ���� �ʱ�ȭ)" << endl;
		m_hp = hp;
		m_attack = attack;
		this->m_defence = defence;
	}

	// �Ҹ���(destructor)
	~Player() {
		cout << "Player �Ҹ�" << endl;
	};
	// ��� �Լ� ->  �Լ�, �޼���� �޸𸮸� �� ���� �ʴ´�. knight 1000���� ���� -> 1000���� �޸� �����ϴ� �� �ƴ�.
	void Attack();
	void Die();
	void Heal(int value);

public:
	// ��� ���� (�Ϲ� ������ �ٸ�)
	int m_hp; // _, m_, m -> �� ��� �����ٶ�� �˷��ִ� ���̹� ��Ģ �� ���� �ٸ�.
	int m_attack;
	int m_defence;

};

