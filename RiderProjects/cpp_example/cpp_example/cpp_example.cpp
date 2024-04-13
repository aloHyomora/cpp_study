// 은행 시스템
#include <iostream>
#include "BankAccount.h"

int main(int argc, char* argv[])
{
    BankAccount myAccount("account1");
    int choice = 0;

    do
    {
        cout << "===============================================" << endl;
        cout << "Hi This is ### Bank! Select option you want :)" << endl;
        cout << "===============================================" << endl;
        cout << "# 1. Show Balance ========" << endl;
        cout << "# 2. Deposit =============" << endl;
        cout << "# 3. Withdraw ============" << endl;
        cout << "# 4. Exit ================" << endl;
        cin >> choice;

        cin.clear(); // 오류 플래그 클리어.
        cin.ignore(); // 입력 버퍼 지우기

        switch (choice)
        {
        case 1:
            myAccount.showBalance();
            break;
        case 2:
            myAccount.deposit();
            myAccount.showBalance();
            break;
        case 3:
            myAccount.withdraw();
            myAccount.showBalance();
            break;
        case 4:
            cout << "Thank you for visiting out services.\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }
    while (choice != 4);

    return 0;
}
