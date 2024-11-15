#include <iostream>
using namespace std;

#include <unordered_map>

enum class ObjectType {
    Player,
    Monster,
    Projectile
};
class Object {
public:
    Object(ObjectType type) : m_type(type) {}    

    virtual ~Object() {}
    

public:
    ObjectType GetObjectType() { return m_type; }
    virtual void Init(){}
    virtual void Update(){}

    int m_id;
    ObjectType m_type;
};

class Player :public Object
{
public:
    Player() : Object(ObjectType::Player) {}
    Player(int id) : Object(ObjectType::Player){}
    
};
class Monster: public Object {
public:
    Monster() : Object(ObjectType::Monster) {}

};

class Projectile : public Object {
    Projectile() : Object(ObjectType::Projectile) {}
};

class Field {
public:
    static Field* GetInstance() {
        static Field field;
        return &field;        
    }
    
    void Update() {
        for (auto& item : _objects) {
            Object* obj = item.second;
            obj->Update();
        }
    }

    void Add(Object* player) {
        _objects.insert(make_pair(player->m_id, player));
    }

    void Remove(int id) {
        _objects.erase(id);
    }

    Object* Get(int id) {
        auto findit = _objects.find(id);

        if (findit != _objects.end())
            return findit->second;
        
        return nullptr;
    }
    // 어떤 자료구조를 사용할까?
    // vector? list? map? hash_map?
    unordered_map<int, Object*> _objects;    
};

int main()
{
    Field::GetInstance()->Add(new Player(1));

    Object* object = Field::GetInstance()->Get(1);

    // 캐스팅 사용하지 않으면 타입을 지정해서 하기도 함.
    if (object && object->GetObjectType() == ObjectType::Player) {
        cout << "플레이어 찾음!" << endl;
    }

    // Object*를 Player*로 변환, Player가 아니라면 nullptr 반환
    if (dynamic_cast<Player*>(object)) {

    }
}
