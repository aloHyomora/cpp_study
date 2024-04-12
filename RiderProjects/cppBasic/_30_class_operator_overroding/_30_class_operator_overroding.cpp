#include <iostream>

using namespace std;

class person
{
private:
    string name;
    int age;
public:
    person(string n, int a) : name(n), age(a){}
    
    // '<<' 연산자를 friend로 선언하여 private 멤버에 접근할 수 있게 함.
    friend ostream& operator<<(ostream& os, person& p);
};
// '<<' 연산자 오버로딩 구현
ostream& operator<<(ostream& os, person& p)
{
    os << "Name : " << p.name << " Age : " << p.age;
    return os;
}
int main(int argc, char* argv[])
{
    person personData("alohyomora", 25);
    cout << personData << endl;
    // Person class를 생성하고 << 연산자로 출력
    return 0;
}
