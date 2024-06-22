#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
using namespace std;

class Monster
{
private:
    string name;
    int health;
    int attackPower;
public:
    // 생성자
    Monster(string monsterName, int hp, int attack);

    // 공격 메서드
    void attack();

    // 데미지를 받는 메서드
    void takeDamage(int damage);

    // 현재 상태 출력 메서드
    void displayStatus();
};

#endif
