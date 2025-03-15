#include "../include/FileDatabase.h"   // 경로 수정 필요

FileDatabase::FileDatabase(const std::string& file) : filename(file) {
    // 파일에서 기존 데이터를 로드하는 코드를 추가할 수 있습니다.
}

bool FileDatabase::addUser(const std::string& name, int age){
    // 파일에 데이터를 추가하기 위해, std::ofstream을 append 모드로 엽니다.
    
    return false;
}

bool FileDatabase::removeUser(const std::string& name){

    return false;
}

int FileDatabase::getUserCount() const {

    return -1;
}