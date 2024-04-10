#include <iostream>
using namespace std;

void HelloCpp(int, int);
// 데이터 형만 작성해도 무방하다.
// 함수 원형과 정의의 매개 변수 형식이 같아야 한다.

int main(int argc, char* argv[])
{
    int times, times2;
    cout << "Write integer num.\n";
    cin >> times;
    cout << "Write integer num.\n";
    cin >> times2;
    HelloCpp(times, times2); // argument 전달 인자
    return 0;
}
void HelloCpp(int n, int m) // parameter 매개 변수
{
    for (int i = 0; i < n; i++)
        cout << "Hello\n";
    
    for (int i = 0; i < m; i++)
        cout << "c++\n";
    
}
