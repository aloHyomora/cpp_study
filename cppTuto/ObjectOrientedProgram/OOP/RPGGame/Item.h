#pragma once

// Item
// - Weapon
// - Armor
// - Consumable

enum ItemRarity
{
	IR_None,
	IR_Normal,
	IR_Rare,
	IR_Unique
};

class Item
{
public:
	Item();
	virtual ~Item();

	// void PrintInfo();
	virtual void PrintInfo(); // ���� �Լ�, ����� ������ �»����� ������ ���� ���
protected:
	int m_itenId = 0;
	int m_itemCount = 0; // ����, ���� 100�� �̻�
	ItemRarity m_rarity = IR_None;
};

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo() override;

	void SetDamage(int damage) { m_damage = damage; }
	int GetDamage() { return m_damage; }
private:
	int m_damage = 0;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();
	
	virtual void PrintInfo() override;

	void SetDefence(int defence) { m_defence = defence; }
	int GetDefence() { return m_defence; }
private:
	int m_defence = 0;
};