#include "pch.h"
#include "Object.h"

Object::Object() : m_type(ObjectType::None), m_stat() 
{
	std::cout << "Object 생성"  << endl;
}



Object::~Object()
{
	std::cout << "Object 소멸" << endl;
}

void Object::PrintStatInfo()
{	
	cout << "[" << (m_type == ObjectType::Player ? "Player" : "Enemy") << " 타입]" << "HP : " << m_stat.hp << ", Attack : " << m_stat.attack << ", Defence : " << m_stat.defence << endl;
	cout << endl;
}
