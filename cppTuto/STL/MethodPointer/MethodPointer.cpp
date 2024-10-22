#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 함수 포인터
// 함수 조차도 포인터로 들고 있을 수 있다.

void Print() {
    cout << "Hello World" << endl;
}

int Add(int a, int b) {
    return a + b;
}

// 콜백 함수
// ex) UI-Button 클릭 시
// ex) 키보드 입력


// 함수 포인터를 왜 쓸까? // 행동 자체를 인자로 넘기고 싶을 때

using FuncPtrType = int(*)(int a, int b);

int DoSomething(int a, int b, FuncPtrType func)
{
    return func(a, b);
}


// 함수 객체
// 함수 포이터의 단점
// - 시그니처가 안 맞으면 사용할 수 없음.
// - 상태를 가질 수 없음

class Functor {
public:
    void operator() () {
        cout << "Functor Test" << endl;
        cout << m_value << endl;
    }
    void operator()(int n) {
        cout << "Functor Test" << endl;
        m_value += n;
        cout << m_value << endl;
    }

public:
    int m_value = 0;
};
using FuncType2 = int(*)(int, int);
struct AddStruct
{
public:
    int operator()(int a, int b) {
        return a + b;
    }
};
template<typename T>
int DoSomething2(int a, int b, T func) {
    // T 타입이라는 객체를 넣어 줄테니 그 객체를 대상으로 func(a, b)를 실행해봐.
    return func(a, b);
}

class MoveJob {
public:
    MoveJob(int x, int y) : x(x), y(y) {}

     

public:
    int x;
    int y;
};

int main()
{
#pragma region regacyUsedCode
    using DataType = int;

    // 함수 포인터 쓰기    
    using FuncType = void(); // void를 반환하는 걸 FuncType 이라 부르겠다.
    using FuncType2 = int(int, int);
    FuncType* ptr = &Print;
    FuncType2* ptr2 = &Add;
    ptr();

    cout << ptr2(10, 10) << endl;

    // 1. 함수 원형
    // void(*FuncPtrType)(); // 옛날 문법
    using FuncPtrType = void(*)();

    FuncPtrType ptr3 = &Print;
    ptr3();
#pragma endregion

#pragma region regacyCode2
    DoSomething(10, 20, &Add);
    DoSomething(10, 20, [](int a, int b) {return a - b; });

    Functor func;
    func.m_value = 10;
    func();
    func(100);

    AddStruct func3;
    DoSomething2(10, 20, func3);
#pragma endregion
    
    
}