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

public:
	void PrintStatInfo();
	virtual void Attack(Object* target);
	virtual void TakeDamage(int damage);
	bool IsLive() {
		cout << "Hp : " << m_stat.hp << endl;
		return m_stat.hp > 0; 
	}

protected:
	Stat m_stat;
	ObjectType m_type;

protected:
	Stat GetStatInfo() const { return m_stat; }
	ObjectType GetObjectType() const { return m_type; }

};

