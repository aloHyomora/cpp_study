#include <iostream>
using namespace std;

class Inventory
{
public:
    Inventory()
    {
        cout << "Inventory()" << endl;
    }
    Inventory(int a)
    {
        _a = a;
        cout << "Inventory(int)" << endl;
    }
    ~Inventory()
    {
        cout << "~Inventory()" << endl;
    }
public:
    int _a;
};

// Is-A? Has-A?
class Player
{
public:
    Player()
    {
        cout << "Player()" << endl;
    }
    ~Player()
    {
        cout << "~Player()" << endl;
    }
};

class  Knight : public Player
{
public:
    Knight() : _hp(0), _inventory(100), _heRef(_hp), _hpConst(_hp) // 초기화 코드, : 이 키워드로만 초기화가능한 것도 존재... &, cosnt
    /*
     * 선처리 영역
     * Player()
     * _inventory = Inventory()
     */
    {
        /*_hp = 0;
        _inventory = Inventory(100);*/
        cout << "Knight()" << endl;
    }
    ~Knight()
    {
        cout << "~Knight()" << endl;
    }
    /*
     * 후처리 ~Player()
     */
public:
    int _hp;

    int& _heRef;
    const int _hpConst;
    Inventory _inventory;
};

int main(int argc, char* argv[])
{
    Knight k1;

    // C# Knight k1 = new Knight();
    // C++ Knight* k1 = new Knight(); 동적 할당.
    
    return 0;
}
