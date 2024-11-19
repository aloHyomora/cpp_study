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
	cout << "[" << (m_type == ObjectType::Player ? "Player" : "Enemy") << " Ÿ��]" << "HP : " << m_stat.hp << ", Attack : " << m_stat.attack << ", Defence : " << m_stat.defence << endl;
	cout << endl;
}
