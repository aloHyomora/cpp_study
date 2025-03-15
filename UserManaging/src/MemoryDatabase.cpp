// MemoryDatabase.cpp
#include "../include/MemoryDatabase.h"
#include <unordered_map>

// 이 구현에선 std::unordered_map을 사용하여 메모리 상에 사용자 정보를 저장합니다.
// unordered_map의 insert/emplae를 통해 효율적인 삽입 및 검색을 구현합니다.

MemoryDatabase::MemoryDatabase() {
    // 기본 생성자: 특별한 초기화 없이 unordered_map은 기본 생성자로 초기화됩니다.
}

bool MemoryDatabase::addUser(const std::string &name, int age)
{
    // emplace는 주어진 인자를 이용해 컨테이너에 새 요소를 생성합니다.
    // result.second가 true이면 삽입 성공, false이면 실패
    auto result = data.emplace(name, age);
    return result.second;
}

bool MemoryDatabase::removeUser(const std::string &name)
{
    // erase는 삭제 후, 삭제된 요소의 수를 반환합니다.
    // 0보다 크면 삭제 성공한 것으로 간주한다.
    return data.erase(name) > 0;
}

int MemoryDatabase::getUserCount() const
{
    // unordered_map의 size()를 통해 저장된 사용자 수를 반환합니다.
    return data.size();
}
