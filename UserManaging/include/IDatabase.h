#ifndef IDATABASE_H
#define IDATABASE_H

#include <string>

// 데이터를 저장, 조회, 삭제하는 공통 메서드를 정의하는 인터페이스
// 이 계층을 통해, 실제 저장소 구현이 어떤 방식이든(파일, 메모리, DB 등) IDatabase를 상속받아 구현하기만 하면 UserManager가 같은 방식으로 사용할 수 있게 됩니다.
class IDatabase // 인터페이스, 추상 계층
{
public:
    virtual ~IDatabase() = default; // 가상 소멸자. 파생 클레스의 객체를 삭제할 때, 올바른 소멸자 호출을 보장한다.
    virtual bool addUser(const std::string& name, int age) = 0; // 순수 가상 함수(=0). 순수 가상 함수는 IDatabase 클래스 내에서 구현을 제공하지 않고, 파생 클래스에서 반드시 구현해야 한다.
    virtual bool removeUser(const std::string& name) = 0;
    virtual int getUserCount() const = 0;
};

#endif
