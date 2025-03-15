#include "include/MemoryDatabase.h"
#include "include/UserManager.h"
#include <memory>


int main() {
    // 메모리 DB 사용 예시
    auto memDB = std::make_unique<MemoryDatabase>();
    UserManager userManager(std::move(memDB));

    userManager.addNewUser("Alice", 30);
    userManager.addNewUser("Bob", 25);
    userManager.printUserCount(); // 2명 출력

    userManager.removeExistingUser("Alice");
    userManager.printUserCount(); // 1명 출력

    return 0;
}
