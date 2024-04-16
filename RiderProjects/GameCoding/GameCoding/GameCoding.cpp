#include <iostream>
#include <string>
#include <variant>

using namespace std;

// 문자열이 정수로만 구성되어 있는지 확인
bool isUserWin(int userInput, int computerValue) {
    cout << "User : " << ((userInput == 0) ? "가위" : userInput == 1 ? "바위" : "보") << " Computer : " << ((computerValue == 0) ? "가위" : computerValue == 1 ? "바위" : "보") << endl;
    if (userInput == 0 && computerValue == 2) return true;
    if (userInput == 1 && computerValue == 0) return true;
    if (userInput == 2 && computerValue == 1) return true;
    return false;
}
int main()  
{
    int n ;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 2; i < 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    
    // simple match
    int hp = 100;
    int damage = 10;
    int round = 1;

    while (true)
    {
        hp -= damage;
        if (hp < 0) {
            hp = 0;
            cout << "제한 라운드 종료! " << endl;
            break;
        }

        cout << "Round " << round << " hp " << hp << endl;

        round++;
    }

    srand(NULL);
    // rock scissor paper
    while (true)
    {
        cout << "가위(1) 바위(2) 보(3) 골라주세요! " << endl;
        cout << "> ";

        int value;
        cin >> value;

        int computerValue = rand() % 3;

        
        if (isUserWin(value, computerValue)) {
            cout << "User Win~!";
            break;
        }
    }
}
