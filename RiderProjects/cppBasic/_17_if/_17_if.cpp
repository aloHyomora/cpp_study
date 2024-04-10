#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // 논리 표현식

    // 논리합과 논리곱을 이용한 코드

    int age;
    cout << "write your age : " << "\n";
    cin >> age;

    if (age < 0 || age > 150)
    {
        cout << "Do not lie to me!\n";
    }
    else if (age >= 20 && age <= 29)
    {
        cout << "you are 20~29\n";
    }
    else
    {
        cout << "I don't know your age.\n";
    }
    return 0;
}
