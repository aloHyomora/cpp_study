#include <iostream>
using namespace std;

// 설계도
class Object
{
public:
    int hp;
};
class IFly
{
    virtual void Fly() = 0;
    virtual void Land() = 0;
    // interface 간접 구현
};
class Player : public Object, public IFly
{
public:
    Player(){}
    ~Player(){}

    virtual void Fly() override {};
    virtual void Land() override {};
    
    void SetUp(int hp) {this->hp = hp;}
    void Move() {}
private:
    int hp = 10;
};
void AddObject(Player* p)
{
    p->SetUp(10);
}
void FlyTest(IFly* fly)
{
    
}
int main(int argc, char* argv[])
{
    Player p;
    FlyTest(&p);
    return 0;
}
