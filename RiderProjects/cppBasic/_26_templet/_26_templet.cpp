#include <iostream>

using namespace std;

// Any 라는 이름으로 템플릿을 만듬.
// class 혹은 typeName
template <class Any>
Any sum(Any, Any);

template <class Any2>
Any2 sum2(int, Any2);

// template에도 오버로딩 적용 가능
template <class  Any2>
Any2 sum2(Any2, Any2);
int main(int argc, char* argv[])
{
    // 함수 템플릿 : 일반화에 대한 서술
    // 구체적인 데이터형을 포괄할 수 있는 일반형으로 함수를 정의
    int a = 3;
    int b = 4;
    cout << sum(a,b) << endl;

    float c = 3.14;
    float d = 1.592;
    cout << sum(c,d) << endl;

    
    // cout << sum(a,d) << endl; Any가 a에 의해 int 타입으로 인식
        
    cout << sum2(a,d) << endl;
    cout << sum2(3.2, 1.1) << endl;
    
    
    return 0;
}
template <class Any>
Any sum(Any a, Any b)
{
    return a + b;
}
template <class Any2>
Any2 sum2(int a, Any2 b)
{
    return a + b;
}
template <class Any2>
Any2 sum2(Any2 a, Any2 b)
{
    return a + b;
}