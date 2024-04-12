// 은행 시스템
#include <iostream>

using namespace std;

class BankAccount
{
private:
    string userName;
    double balance;
public:

    BankAccount();
    BankAccount(const string &userName);
    BankAccount(const string &userName, double dollar);
    ~BankAccount();

    // method
    void resetUserInfo();
    void showBalance();
    double deposit();
    double withdraw();
};

// constructor, destroyer
BankAccount::BankAccount() : userName(""), balance(0)
{
    resetUserInfo();
}
BankAccount::BankAccount(const string &name) : userName(name), balance(0)
{
    resetUserInfo();
}
BankAccount::BankAccount(const string &name, double dollar): userName(name), balance(dollar){}
BankAccount::~BankAccount()
{
}

void BankAccount::resetUserInfo()
{
    if(userName == "")
    {
        cout << "You missed entering your name. please Enter your name.\n";
        cin >> userName;
    }
    if (balance <= 0)
    {
        cout << "You have to prepare money, when you open a bank account. \n";
        cin >> balance;
    }
}

void BankAccount::showBalance()
{
    
}
double BankAccount::deposit()
{
    
}
double BankAccount::withdraw()
{
    
}


int main(int argc, char* argv[])
{
    // BankAccount myAccount
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

        cin.clear();  // 오류 플래그 클리어.
        cin.ignore(); // 입력 버퍼 지우기

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }
    while (choice != 4);
    
    return 0;
}
