#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include <vector>
#include "Item.h"
#include <memory>

class Player
{
private:
    string name;
    int maxHealth;
    int health;
    int attackPower;
    int experience;
    int level;
    vector<unique_ptr<Item>> inventory; // 아이템 포인터 벡터
public:
    // 생성자
    Player(string playerName);

    // 소멸자
    ~Player(); // 메모리 누수를 방지하기 위해 소멸자 추가
    
    // 공격 메서드
    void attack();
    
    // 데미지를 받는 메서드
    void takeDamage(int damage);

    // 경험치 획득 메서드
    void gainExperience(int exp);

    // 레벨업 메서드
    void levelUp();

    // 현재 상태 출력 메서드
    void displayStatus() const;

    // 플레이어 공격력 반환 메서드
    int getAttackPower() const;

    // 플레이어 체력 반환 메서드
    int getHealth() const;

    // 아이템 사용 메서드
    void useItem(int index);

    // 아이템 포인터 추가 메서드
    void addItem(unique_ptr<Item> item);
};

#endif
