#include <iomanip>
#include <iostream>

using namespace std;

const int MAX = 100;
int board[MAX][MAX];
int N;

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    cin >> N;

    PrintBoard();
    
    return 0;
}
