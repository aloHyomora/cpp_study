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
	virtual ~Object();

protected:
	Stat m_stat;
	ObjectType m_type;


protected:
	Stat GetStatInfo() const { return m_stat; }
	ObjectType GetObjectType() const { return m_type; }
	void PrintStatInfo();
};

