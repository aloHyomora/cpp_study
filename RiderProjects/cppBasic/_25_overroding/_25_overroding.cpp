#include <iostream>

using namespace std;

void print(char, int);
void print(int, int);
void print(char);

int sum(int, int);
float sum(float, float);

int main(int argc, char* argv[])
{
    // 함수의 오버로딩
    // 여러 개의 함수를 같은 이름으로 연결한다.

    /*1. 함수의 리턴형만 다를 경우
    2. 함수를 사용할 때, 두 개 이상의 함수에 대응되는 경우*/

    cout << "두 정수를 입력하십시오." << endl;
    int a, b;
    cin >> a >> b;
    cout << "두 정수의 합은 " << sum(a, b) << endl;

    cout << "두 실수를 입력하십시오." << endl;
    float c, d;
    cin >> c >> d;
    cout << "두 실수의 합은 " << sum(c, d) << endl;
    
    return 0;
}
int sum(int n, int k)
{
    return n + k;
}
float sum(float n, float k)
{
    return n + k;
}