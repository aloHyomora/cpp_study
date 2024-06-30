#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
protected:
    string name;
public:
    Item(string itemName);
    virtual ~Item() {}

    string getName() const;

    // 순수 가상 함수
    virtual void use() const = 0;
};

class HealthPotion : public Item
{
private:
    int healingAmount;
public:
    HealthPotion(string itemName, int healAmount);
    void use() const override;
};

class AttackBoost : public Item
{
private:
    int boostAmount;
public:
    AttackBoost(string itemName, int boostAmt);
    void use() const override;
};
#endif