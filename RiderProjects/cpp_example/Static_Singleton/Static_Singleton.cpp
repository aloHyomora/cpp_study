#include <iostream>
using namespace std;

// struct vs class
// C++은 비슷하게 동작

// static 특정 객체에 종속적인가를 생각해보자.
class Marine
{
public:
    void TakeDamage(int damage)
    {
        hp -= damage;
    }
    // 특정 마린 객체와 연관
    static void SetAttack(int value)
    {
        // hp = 100;과 같은 특정 마린 객체와 연관된 작업은 할 수 없다.
    }
public:
    // 특정 마린 객채와 연관
    int hp = 40;
    // 특정 마린 객체와 무관
    static int attack;
};
int Marine::attack = 6;


class Player
{
public:
    Player()
    {
        id = s_idGenerator++;
    }
public:
    int id;
    static int s_idGenerator;
};
// ======== 싱글톤 =========
// 싱글톤, 옵저버, 컴포넌트...
// 싱글톤 : 딱 1개만 존재하고 어디서든 사용가능한
class UserManager
{
public:
    static UserManager* GetInstance()
    {
        static UserManager um;
        return &um;
    }
public:
    void AddUser() {_userCount++;}
    int GetUserCount() {return _userCount;}
private:
    int _userCount = 0;
};

#define GET_MANAGER (UserManager::GetInstance())
int main(int argc, char* argv[])
{
    /*Marine marine;
    marine.SetAttack(10);*/
    /*Marine m1;
    m1.hp = 40;

    Marine m2;
    m2.hp = 60;*/

    Player p1; // id 1
    Player p2; // id 2
    Player p3; // id 3 

    for(int i = 0; i < 10; i++)
    {
        GET_MANAGER->AddUser();
        UserManager::GetInstance()->AddUser();
    }
    
    return 0;
}
