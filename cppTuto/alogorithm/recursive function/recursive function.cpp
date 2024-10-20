#include <iostream>

using namespace std;

void Func(int a) {
    if (a == 0) return;

    cout << a << endl;

    Func(a - 1);
}

// Factorial -> 5! = 5*4*3*2*1 = 5 * 4!
// n! = n * (n-1)!

int Factorial(int n)
{
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}

// 유클리드 호재법 : 두 수의 최대 공약수를 구하는 알고리즘
// a > b
// GDD(1071, 1029)
// = GCD(1029, 1071%1029=42)
// = GCD(42, 1029%42=21)
// = GCD(21,0) = 21

int Gcd(int a, int b) {
    if (b == 0) return a;

    return Gcd(b, a % b);
}
int main()
{
    Func(5);

    cout << endl;

    cout << Factorial(5) << endl;
    cout << Gcd(1071, 1029) << endl;
}

// Stack Overflow
// Stack 이라는 것 자체가 어떤 공간을 할당해놓고 함수가 호출될 때마다 공간을 주고 사용
// 함수끼리의 공용 메모리 공간이었는데, 함수가 끝나지 않고 그 스택 메모리 공간을 사용하고 또 사용하다보니 
// 공용 메모리 공간을 가득 채웠다.

// 재귀 함수의 장점
// 트리 Tree


