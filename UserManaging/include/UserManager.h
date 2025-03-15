#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <memory>
#include "IDatabase.h"

class UserManager
{
private:
    std::unique_ptr<IDatabase> db;
public:
    // 생성자에서 어떤 Database를 쓸지 주입(Dependency Injection)
    explicit UserManager(std::unique_ptr<IDatabase> database);

    void addNewUser(const std::string& name, int age);
    void removeExistingUser(const std::string& name);
    void printUserCount() const;
};

#endif