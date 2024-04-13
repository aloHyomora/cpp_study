#include "BankAccount.h"

// constructor, destroyer
BankAccount::BankAccount() : userName(""), balance(0)
{
    resetUserInfo();
}

BankAccount::BankAccount(const string& name) : userName(name), balance(0)
{
    resetUserInfo();
}

BankAccount::BankAccount(const string& name, double dollar): userName(name), balance(dollar)
{
    resetUserInfo();
}

BankAccount::~BankAccount()
{
}

void BankAccount::resetUserInfo()
{
    if (userName == "")
    {
        cout << "You missed entering your name. please Enter your name.\n";

        // Repeat if the user input is not of string type.
        while (!(cin >> userName))
        {
            cout << "Invalid input. Please enter a string value.\n";

            // Execute if there is an error (failbit) in the input stream.
            // Clear the error state of cin to make the stream usable again.                                                                                                                                                                                                                                 
            cin.clear();

            // Empty the current input buffer to prevent the next input from being affected by incorrect data.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Request the user agin for the correct input.
        }
    }
    if (balance <= 0)
    {
        cout << "You have to prepare money, when you open a bank account. \n";

        while (!(cin >> balance))
        {
            cout << "Invalid input. Please enter a numeric value.\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "You entered : " << userName << endl;
    cout << "You entered " << balance << endl;
    return;
}

void BankAccount::showBalance()
{
    cout << "=============Bank Account============\n";
    cout << "Name : " << userName << endl;
    cout << "Balance : " << balance << endl;
    cout << "=====================================\n";
}



void BankAccount::deposit()
{
    double money;
    cout << "=============Bank Account============\n";
    cout << "Hi " << userName << " Deposit Money : ";
    while (!(cin >> money))
    {
        cout << "Invalid input. Please enter a numeric value.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "Your existing balance was " << balance << "$. now you deposited " << money << endl; 
    balance += money;
    return;
}

void BankAccount::withdraw()
{
    double money;
    cout << "=============Bank Account============\n";
    cout << "Hi " << userName << " Withdraw Money : ";
    while (!(cin >> money) || money >= balance)
    {
        cout << "Invalid input. Please enter a numeric value.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "Your existing balance was " << balance << "$. now you withdraw " << money << endl; 
    balance -= money;
    return;
}
