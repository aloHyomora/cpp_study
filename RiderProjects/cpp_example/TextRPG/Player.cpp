#include "Player.h"

Player::Player(string playerName)
    : name(playerName), maxHealth(100), health(100), attackPower(10), experience(0), level(1){}
Player::~Player()
{
    // 인벤토리 아이템 삭제
    for (Item* item : inventory)
    {
        delete item;
    }
}
void Player::attack()
{
    cout << name << " attacks with power " << attackPower << "!\n";
}
void Player::takeDamage(int damage)
{
    health -= damage;
    if(health < 0) health = 0;
    cout << name << " takes " << damage << " damage. Health is now " << health << ".\n";
}
void Player::gainExperience(int exp)
{
    experience += exp;
    cout << name << " gains " << exp << " exp!.\n";
    if(experience >= 100) levelUp();
}
void Player::levelUp()
{
    level++;

    maxHealth += 50;
    health = maxHealth;
    attackPower += 5;

    experience = 0;
    cout << name << " levels up to " << level;
}
void Player::displayStatus() const
{
    cout << "===========================================\n";
    cout << "Player: " << name
        << "\nHealth: " << health
        << "\nAttack Power: " << attackPower
        << "\nexperience" << experience
        << "\nlevel" << level << "\n";
    cout << "===========================================\n";
}
int Player::getAttackPower() const
{
    return attackPower;
}
int Player::getHealth() const
{
    return health;
}
void Player::addItem(Item* item)
{
    inventory.push_back(item);
}
void Player::useItem(int index)
{
    if(index >= 0 && index < inventory.size())
    {
        inventory[index]->use(); // 아이템의 use 메서드 호출
        delete inventory[index]; // 사용한 아이템 메모리 해제
        inventory.erase(inventory.begin() + index); // 인벤토리에서 삭제
    }
    else
    {
        cout << "Invalid item index.\n";
    }
}

