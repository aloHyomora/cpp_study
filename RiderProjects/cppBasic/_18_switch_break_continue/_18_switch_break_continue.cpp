#include <complex.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // 공백 처리하기
    cout << "write sentence.\n";
    char line[30];
    cin.get(line,30);
    cout << "you wrote :";

    int spaces =0;
    for (int j = 0; line[j] != '\0'; j++)
    {
        cout << line[j];

        if(line[j] == ' ')
            continue;

        spaces++;
    }
    cout << " right? \n";
    cout << "total alphabet num is " << spaces << endl;
    cout << "for end";
    
    
    // continue, break
    int i = 0;
    while (true)
    {
        cout << "i value : " << i << endl;
        i++;
        if(i == 5) continue;
        if(i>10) break;
    }


    // switch
    int a;
    cout << "Write integer number : ";
    cin >> a;

    switch (a)
    {
    case 1:
        cout << "num 1\n";
        break;
    case 2:
        cout << "num 2\n";
        break;
    case 3:
        cout << "num 3\n"; 
        break;
    default:
        cout << "another value.\n";
        break;
    }

    cout << "switch end";
    return 0;
}
