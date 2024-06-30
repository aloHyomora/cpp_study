#include "Item.h"
#include <iostream>

Item::Item(string itemName)
    : name(itemName) {}

string Item::getName() const
{
    return name;
}

HealthPotion::HealthPotion(string itemName, int healAmount)
    : Item(itemName), healingAmount(healAmount) {}

void HealthPotion::use() const
{
    cout << "Using " << name << ". Restores " << healingAmount << " hp.\n";
    // TODO : 플레이어 체력 회복 코드 추가
}

AttackBoost::AttackBoost(string itemName, int boostAmt)
    : Item(itemName), boostAmount(boostAmt) {}

void AttackBoost::use() const
{
    cout << "Using " << name << ". Increases attack power by " << boostAmount << ".\n";
    // TODO : 플레이어 공격력 증가 코드 추가
}



