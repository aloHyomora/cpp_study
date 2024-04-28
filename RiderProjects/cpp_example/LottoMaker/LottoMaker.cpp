#include <iostream>
using namespace std;

// 로또 번호 생성기
void Swap(int& a, int& b)
{
    int temp = a;
    a=b;
    b = temp;
}

void Sort(int* numbers, int count)
{
    // 버블 정렬 => 왼쪽 오른쪽 검사, 바꿔치기
    // {1, 42, 3, 15, 6, 5} => {1, 3, 5, 6, 15, 42}

    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < count - 1; i++)
        {
            if(numbers[i] > numbers[i+1])
                Swap(numbers[i], numbers[i+1]);
        }    
    }
}

void ChooseLotto(int* numbers)
{
    int count = 0;

    while (count != 6)
    {
        // 1~45
        int randValue = 1 + rand() % 45;
        
        // 이미 찾은 값인지?
        bool found = false;
        
        for (int i = 0; i < count; i++)
        {
            if(numbers[i] == randValue)
            {
                found = true;
                break;
            }
        }

        if(found == false)
        {
            numbers[count] = randValue;
            count++;
        }
    }

    Sort(numbers, 6);
}

int main(int argc, char* argv[])
{
    srand(time(nullptr));
    
    int lotto[6]; // = {1, 42, 3, 15, 6, 5};
    // Sort(lotto, 6);
    ChooseLotto(lotto);

    for (int i = 0; i < 6; i++)
    {
        cout << lotto[i] << endl;
    }
    
    return 0;
}
