#ifndef FILEDATABASE_H
#define FILEDATABASE_H

#include "IDatabase.h"

class FileDatabase : public IDatabase // 구현 계층 #2) 파일에 사용자 정보를 저장
{
private:
    std::string filename;
public:
    explicit FileDatabase(const std::string& file);
    bool addUser(const std::string& name, int age) override;
    bool removeUser(const std::string& name) override;
    int getUserCount() const override;
};

#endif