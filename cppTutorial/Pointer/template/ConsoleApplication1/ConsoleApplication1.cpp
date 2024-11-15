#include <iostream>

using namespace std;

// 함수 템플릿
// 클래스 템플릿

// 컴파일하는 시점에 연산이 된다.

// 이렇게 사용하지 않고
//void Print(int a) {
//
//}
//void Print(float a) {
//
//}

// 여러가지 버전을 통용시키는 목적이 아니다.
// 조커카드 1개 (T에 원하는 타입을 넣어서 사용 가능)
template<typename T>
void Print(T a) {
    cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b) {
    cout << a << " " << b << endl;
}

template<>
void Print(int a) {
    cout << "int" << endl;
}

// =======================
// 클래스 템플릿
template<typename T> // , int SIZE> 로 넣고 초기 값을 넣을 수 있다. template<typename T = int, int SIZE = 100>
class RandomBox {
public:
    T GetRandomData() {
        int index = rand() % 100;
        return m_data[index];
    }
public:
    T m_data[100];
};

// 특수화 - int로 특수하게 지정해서 만드는 것도 가능하다!
template<>
class RandomBox<int>
{
public:
    int GetRandomData() {
        int index = rand() % 100;
        return m_data[index];
    }
public:
    int m_data[100];
};

int main()
{
    Print(1); // Print<int>(1) 과 동일, 우리 만의 버전으로 template<>으로 작성된 버전을 호출한다.
    Print(1.23);
    Print("Hellow~~~");

    Print(1, "Rookiss");
    Print<int, const char*>(3, "hyo");

    RandomBox<int> rb1;   // int 타입으로 생성됨.
    RandomBox<float> rb2; // float 타입으로 생성됨.
}

// 