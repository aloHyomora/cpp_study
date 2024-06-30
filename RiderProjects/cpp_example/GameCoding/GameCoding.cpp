#include <iostream>
using namespace std;

/*int main(int argc, char* argv[])
{
    // C 스타일 캐스팅 (값 타입 변환)
    // 특징) 의미를 유지하기 위해서 원본 객체와 다른 비트열 재구성
    {
        int a = 123456789;
        float b = (float)a; 
        int c = 0;
    }
    // 참조 타입 변환
    {
        int a = 123456789;
        float b = (float&)a; 
        int c = 0;
    }
    // 안전한 변환 (의미가 100% 일치)
    {
        int a = 123456789;
        __int64 b= (__int64)a;
        int c = 0;
    }
    // 불안전한 변환
    {
        int a = 123456789;
        short b= (short)a;
        int c = 0;
    }
    // 암시적 변환
    {
        int a = 123456789;
        float b = a;
    }
    
    return 0;
}*/
class Player
{
public:
    
};

class Knight : public Player
{
public:
    
};

class Dog
{
public:
    int age;
};
int main()
{
    // C 스타일 캐스팅
    Knight* k = new Knight();

    Dog* dog = (Dog*)k; // 일단 통과 시켜줌.
    dog->age = 10;
}

// Q1. Knight 타입 변수를 Dog로 변환하고 dog의 변수에 접근할 때 생기는 문제
// 접근할 때 쓰레기 값이 나온다. 클래스 마다 메모리 구조가 다르기 때문이다. 