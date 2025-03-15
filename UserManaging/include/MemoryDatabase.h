#ifndef MEMORYDATABASE_H
#define MEMORYDATABASE_H

#include "IDatabase.h"
#include <unordered_map>

class MemoryDatabase : public IDatabase // 구현 계층 #1) unordered_map 같은 메모리에 사용자 정보를 저장
{
private:
    std::unordered_map<std::string, int> data;
public:
    MemoryDatabase();
    bool addUser(const std::string& name, int age) override;
    bool removeUser(const std::string& name) override;
    int getUserCount() const override;
};

#endif