#include "Monster.h"
#include "Player.h"

Monster::Monster(string monsterName, int hp, int attack)
    : name(monsterName), health(hp), attackPower(attack){}

void Monster::attack(Player& player)
{
    cout << name << "(Monster) attacks with power " <<attackPower << "!\n";
    player.takeDamage(attackPower);
}

void Monster::takeDamage(int damage)
{
    health -= damage;
    if(health < 0) health = 0;
    cout << name << " takes " << damage << " damage. Health is now " << health << ".\n";
}

void Monster::displayStatus() const
{
    cout << "===========================================\n";
    cout << "Monster: " << name
        << "\nHealth: " << health
        << "\nAttack Power: " << attackPower<< "\n";
    cout << "===========================================\n";
}

int Monster::getHealth() const
{
    return health;
}
