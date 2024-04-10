#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int a[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        cout << a[i]; // 13579
    }
    cout <<"\n";

    for (int i : a)
    {
        cout << i; // 13579
    }
    cout <<"\n";

    
    int b[10] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++)
    {
        cout << b[i]; // 13579
    }
    cout <<"\n";

    for (int i : b)
    {
        cout << i; // 1357900000
    }
    cout <<"\n";

    // 중첩 루프 : 2차원 배열
    int temp[4][5] ={
        {1, 2, 3, 4, 5},
        {11, 22, 33, 44, 55},
        {111, 222, 333, 444, 555},
        {1111, 2222, 3333, 4444, 5555}
    };
    
    for (int row = 0; row <4; row++)
    {
        for (int col = 0; col <5; col++)
        {
            cout << temp[row][col] << " ";
        }
        cout << "\n";
    }

    
    return 0;
}
