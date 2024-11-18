#pragma once

enum class ObjectType {
	None,
	Player,
	Enemy
};

class Object
{
public:
	Object();
	Object(ObjectType objectType);
	virtual ~Object();
protected:
	ObjectType _type;
	Stat GetStatInfo() { return _stat; }
	Stat _stat = {};
	void PrintStatInfo();
};

