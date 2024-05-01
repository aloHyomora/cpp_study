#include <iostream>
using namespace std;

// 연산자 오버로딩
// - 멤버 연산자 함수 버전
// a op b 에서 왼쪽을 기준으로 실행

// - 전역 연산자 함수 버전
// a op b 형태라면, a/b 모두 피연산자로 사용 
class Pos
{
public:
    Pos()
    {
        
    }
    explicit Pos(int b) // explicit : 초기화 문법에서 아니면 대입할 때 요렇게 간접적으로 넣는 걸 막아줌. 암시적으로 변환되어 넘어오는 걸 예방
    {
        x = b;
        y = b;
    }
    
    Pos operator+(const Pos& b)
    {
        Pos pos;
        pos.x = x + b.x;
        pos.y = y + b.y;
        return pos;
    }
    Pos operator+(int b)
    {
        Pos pos;
        pos.x = x + b;
        pos.y = y + b;
        return pos;
    }
    bool operator==(const Pos& b)
    {
        return x == b.x && y == b.y;
    }

    // 대입 연산자
    void operator=(int b)
    {
        x = b;
        y = x;
    }
public:
    
    int x, y = 0;
};

Pos operator+(int a, const Pos& b)
{
    Pos pos;
    pos.x = a + b.x;
    pos.y = a + b.y;
}
void TestPos(Pos a)
{
    
}
int main(int argc, char* argv[])
{
    // TestPos(10);
    Pos pos1;
    Pos pos2;
    Pos pos3 = pos1 + pos2;
    // pos3 = pos1.operator+(pose); 동일


    Pos pos4(30);// = 30;
    // Pos pos5 = 40; // 생성자 호출
    
    // 대입 연산
    pos1 = 10;
    pos2 = 20; // void operator+ 호출
    
    return 0;
}
