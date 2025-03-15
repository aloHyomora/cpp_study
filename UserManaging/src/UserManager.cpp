// UserManager.cpp
#include "../include/UserManager.h"
#include <iostream>

// UserManager는 데이터베이스 인터페이스(IDatabase)에 의존합니다.
// 여기서는 스마트 포인터(std::unique_ptr)를 사용하여 의존성 주입(Dependency Injection)을 구현합니다.

// 소유권 이전: std::move()를 사용하여 unique_ptr을 이동합니다.
UserManager::UserManager(std::unique_ptr<IDatabase> database) : db(std::move(database)){
    // 생성자에서 데이터베이스 객체를 주입받습니다.
}

void UserManager::addNewUser(const std::string &name, int age)
{
    // 데이터베이스에서 사용자를 추가하고 결과를 출력합니다.
    if(db->addUser(name, age)){
        std::cout << "User " <<name << " added successfully.\n";
    }else{
        std::cout << "Failed to add user " <<name << ".\n";
    }
}

void UserManager::removeExistingUser(const std::string &name)
{
    // 데이터베이스에서 사용자를 제거하고 결과를 출력합니다.
    if(db->removeUser(name)){
        std::cout << "User " <<name << " removed successfully.\n";
    }else{
        std::cout << "Failed to remove user " <<name << ".\n";
    }
}

void UserManager::printUserCount() const
{
    // 데이터베이스에 저장된 총 사용자를 출력합니다.
    std::cout << "Total users: " << db->getUserCount() << "\n";
}