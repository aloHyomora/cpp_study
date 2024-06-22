#include "Player.h"

Player::Player(string playerName)
    : name(playerName), maxHealth(100), health(100), attackPower(10), experience(0), level(1){}
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
