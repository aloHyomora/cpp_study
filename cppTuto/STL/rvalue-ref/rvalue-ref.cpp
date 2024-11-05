#include <iostream>
#include <list>

using namespace std;

class Knight {
public:
    Knight() {

    }

    ~Knight() {

    }

    // 컴파일러는 알아서 만들어 주고 있었다.
    // 복사 생성자
    Knight(const Knight& knight) {

    }
    // 복사 대입 연산자
    void operator=(const Knight& knight) {

    }

    // 이동 생성자
    // 이동 대입 생성자

public:
    int m_hp = 0;
};

// 복사 (Knight가 크면 비효율적)
void TestKnight_Copy(Knight knight) {

}
// 참조 원본 넘겨줄테니
void TestKnight_LValueRef(Knight& knight) {

}
// 원본 넘겨줄테니... 건드릴 순 없어.
void TestKnight_ConstLValueRef(const Knight& knight) {
    // knight.m_hp = 0;
}
// 원본 넘겨줄테니... 더 이상 활용하지 않을테니 맘대로 해! 라는 힌트를 준다.
void TestKnight_RValueRef(Knight&& knight) {
    // knight.m_hp = 0;
}
int main()
{
#pragma region R-Value
    // C++ 11 오른값 참조
    // 왼값(l-value) vs 오른값(r-value)
    // l-value : 단일식을 넘어서 계속 지속되는 개체
    // r-value : l-value가 아닌 나머지

    int a = 3; // a(왼값), 3(오른값)

    Knight k1;
    Knight k2;

    TestKnight_Copy(k1);
    TestKnight_LValueRef(k1);
    // TestKnight_LValueRef(Knight()); // 오류 : 비 const 참조에 대한 초기 값은 lvalue여야 한다. 왼값만 넣을 수 있다.
    TestKnight_ConstLValueRef(Knight()); // const가 붙은 애는 오른값(r-value도 가능)   // 임식 객체인 오른값을 넘겨줌.임시 객첸데 가지고 있어야 하나?
    
    // TestKnight_RValueRef(k1); // 오류 : 왼값 X
    TestKnight_RValueRef(static_cast<Knight&&>(k1));    // 오른 값으로 변경해서 대입
    TestKnight_RValueRef(Knight());

    // 아래 두 문장 완전히 동일
    // k2 = static_cast<Knight&&>(k1);
    k2 = std::move(k1);
#pragma endregion
}

