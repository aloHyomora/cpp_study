#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    for(int i = 0; i <5; i++)
    {
        cout << "Time : " << i << endl;        
    }

    // 증가, 감소 연산자
    int a = 10, b =  10;
    cout << "a : " << a << ", b : " << b << endl;
    cout << "a++ : " << a++ << " ";
    cout << "++b : " << ++b << endl;

    int i = 0;
    while (i < 3)
    {
        i++;
    }

    int j = 0;
    string str = "Panda";
    while (str[j] != '\0')
    {
        cout << str[j] << endl;
        j++;
    }

    int k = 0;
    do
    {
        cout << "while statement.\n";
        k++;
    }
    while (k < 3);
    
    return 0;
}
