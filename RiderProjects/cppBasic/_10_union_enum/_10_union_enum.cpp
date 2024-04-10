#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // union(공용체)
    // 서로 다른 데이터 형을 한 번에 한 가지만 보관할 수 있다.

    union my_union
    {
        int intVal;
        long longVal;
        float floatVal;
    };

    my_union test;
    test.intVal = 3;
    cout << test.intVal << endl; // 3
    test.longVal = 33;
    cout << test.intVal << endl; // 33
    cout << test.longVal << endl; // 33
    test.floatVal =3.3;
    cout << test.intVal << endl; // ~~
    cout << test.longVal << endl; // ~~
    cout << test.floatVal << endl; // 3.3

    // enum (열거체)
    // 기호 상수를 만드는 또다른 방법

    enum spectrum
    {
        red, orange, yellow, green, blue, violet, indigo
    };
    enum fruit
    {
        apple = 0, banana = 2, melon = 4, grape, mango
        // 선언되지 않은 grape, mango는 각각 마지막으로 값이 할당된 melon 뒤의 인덱스인 5, 6이 대입된다.
    };
    /*
     * 1. spectrum을 새로운 데이터형 이름으로 만든다.
     * 2. 0에서 6까지 정수 값을 각각 나타내는 기호 상수로 나타낸다.
     */
    // enum 변수끼리 연산은 안됨.
    // int 형 변수에 값을 대입해서 계산하는 것은 가능.
    spectrum a = orange;
    cout << a << endl;

    int b = blue;
    int c = blue +3;
    
    return 0;
}
