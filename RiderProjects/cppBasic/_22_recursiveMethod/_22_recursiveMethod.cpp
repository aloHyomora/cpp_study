#include <iostream>

using namespace std;

void CountDown(int);
int func(int);
int main(int argc, char* argv[])
{
    // recursive(재귀) : method can call itself in c++
    // CountDown(5);

    // pointer that indicates method
    // in special situation, it will be useful to get method's address by parameter
    /*
     * 1. 함수의 주소를 얻는다.
     * 2. 함수를 지시하는 포인터를 사용한다.
     * 3. 함수를 지시하느느 포인터를 사용하여 그 함수를 호출한다.
     */
    // cout << func << endl;

    // int형 매개변수를 가지는 int형 포인트를 만들고 싶다.
    int (*pf)(int);
    pf = func;

    cout << (*pf)(3) << endl;
    
    return 0;
}
void CountDown(int n)
{
    cout << "Counting... " << n << endl;
    if (n >0)
        CountDown(n - 1);
    cout <<  n << "th times Recursive method" << endl;
    
}
int func(int n)
{
    return n+1;
}