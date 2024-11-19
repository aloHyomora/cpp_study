#include "pch.h"
#include "Object.h"

Object::Object() : m_type(ObjectType::None), m_stat() 
{
	std::cout << "Object ����"  << endl;
}


Object::~Object()
{
	std::cout << "Object �Ҹ�" << endl;
}

void Object::PrintStatInfo()
{	
	cout << "[" << (m_type == ObjectType::Player ? "Player" : "Enemy") << " Ÿ��]" << "HP : " << m_stat.hp << ", Attack : " << m_stat.attack << ", Defence : " << m_stat.defense << endl;
	cout << endl;
}

void Object::Attack(Object* target)
{
	if (target == nullptr) {
		cout << "No target to attack!" << endl;
		return;
	}

	// ������ ��� (�ڽ��� ���ݷ� - Ÿ���� ����)
	int damage = m_stat.attack - target->m_stat.defense;
	if (damage < 0) damage = 0;

	cout << (m_type == ObjectType::Player ? "Player" : "Enemy") <<" attacks for " << damage << " damage!" << endl;

	// ��󿡰� ������ ����
	target->TakeDamage(damage);

}

void Object::TakeDamage(int damage)
{
	m_stat.hp -= damage;
	if (m_stat.hp < 0) m_stat.hp = 0;		

	std::cout << (m_type == ObjectType::Player ? "Player" : "Enemy") <<" took " << damage << " damage. Remaining HP: " << m_stat.hp << std::endl;
}
