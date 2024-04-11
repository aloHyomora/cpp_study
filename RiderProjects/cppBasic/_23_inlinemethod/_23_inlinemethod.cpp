#include <iostream>

using namespace std;

// 프로그램의 실행 속도를 줄이기 위해 지원
inline float square(float x) {return x*x;} 
const int SIZE = 8;
int sumArr(int*, int n = 1);
int main(int argc, char* argv[])
{
    // 인라인 함수
    /*
     *일반적으로 함수의 호출은 함수의 주소로 점프하는 과정
     *인라인 함수는 컴파일된 함수 코드가 프로그램의 다른 코드에 삽입
     *컴파일러의 인라인 함수 호출 => 점프가 아닌 그에 대응하는 함수 코드로 대체    
     */
    int a = 5;
    cout << "d : " << a << endl;
    float b = square(a);
    cout << b << endl;


    // default parameter
    int arr[SIZE] = {1,2,4,8,16,32,64,128};
    int sum = sumArr(arr, SIZE); 
    cout << "total : " << sum << endl;

    // 유저가 argument를 전달하지 않았을 때 default 전달
    // default 값은 함수 원형에 정의됨.
    int sum2 = sumArr(arr); 
    cout << "total : " << sum2 << endl;
    
    return 0;
}
int sumArr(int* arr, int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}
