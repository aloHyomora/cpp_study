#include <iostream>

using namespace std;

const int SIZE = 8;
int SumArr(int[], int);
int SumArr2(int* begin, int* end);
// int SumArr(int*, int);
int main(int argc, char* argv[])
{
    // 함수는 복잡한 데이터를 다루는 데에도 사용할 수 있다.

    // c++ 배열에서 봐야할 점.
    // c++ 배열은 사실 포인터이다.
    // c++에서 배열 이름을 그 배열의 첫 번째 원소의 주소로 인식한다.
    // arr == &arr[0]

    int arr[SIZE] = {1,2,4,8,16,32,64,128};
    cout << "Size of arr " << sizeof arr << endl;
    // result : Size of arr 32
    // 배열의 크기가 반환됨.
    
    int sum = SumArr(arr, SIZE);

    cout << "Sum of Arrays " << sum << endl;

    cout << "Sum of Arrays(address) " << endl;
    int sum2 = SumArr2(arr, arr+SIZE);
    cout << "Sum of Arrays(address) " << sum2 << endl;
    return 0;
}

// SumArr로 전달되는 매개 변수 arr[]가 그 자체로 전달된다면, n이 필요없겠지만
// 전달받는 것은 배열의 시작 주소이기 때문에 이 배열의 전체적인 크기를 전달받은 것이다.
int SumArr(int arr[], int n) // int SumArr(int* arr, int n)
{
    cout << "Size of arr " << sizeof arr << endl;
    // result : Size of arr 8
    // 포인터의 크기가 반환됨.
    
    int total = 0;

    for (int i = 0; i< n; i++)
        total += arr[i];
    
    return total;
}
// 배열의 시작 주소, 끝 주소를 알려주는 방법도 있다.
int SumArr2(int* begin, int* end) // int SumArr(int* arr, int n)
{
    int total = 0;
    int* pt;
    
    for (pt = begin; pt != end; pt++)
        total += *pt;
    
    return total;
}