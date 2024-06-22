#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
class Player
{
private:
    string name;
    int maxHealth;
    int health;
    int attackPower;
    int experience;
    int level;
public:
    // 생성자
    Player(string playerName);

    // 공격 메서드
    void attack();
    
    // 데미지를 받는 메서드
    void takeDamage(int damage);

    // 경험치 획득 메서드
    void gainExperience(int exp);

    // 레벨업 메서드
    void levelUp();

    // 현재 상태 출력 메서드
    void displayStatus();
};

#endif
