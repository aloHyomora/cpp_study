#ifndef BANKACCOUNT
#define BANKACCOUNT

#include <iostream>
using namespace std;

class BankAccount
{
private:
    string userName;
    double balance;
public:
    BankAccount();
    BankAccount(const string& userName);
    BankAccount(const string& userName, double dollar);
    ~BankAccount();

    // method
    void resetUserInfo();
    void showBalance();
    void deposit();
    void withdraw();
};

#endif