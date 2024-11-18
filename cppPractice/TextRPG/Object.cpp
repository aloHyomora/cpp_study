#include "pch.h"
#include "Object.h"

Object::Object()
{
}

Object::Object(ObjectType objectType) : _type(objectType)
{
}

Object::~Object()
{
}

void Object::PrintStatInfo()
{
	cout << (_type == ObjectType::Player ? "Player" : "Enemy") << " е╦ют" << endl;
	cout << "HP : " << _stat.hp << ", Attack : " << _stat.attack << ", Defence : " << _stat.defence << endl;
	cout << endl;
}
