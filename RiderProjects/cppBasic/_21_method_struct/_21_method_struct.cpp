#include <iostream>

using namespace std;

struct Time
{
    int hours;
    int mins;
};

const int minsPerHr = 60;
Time sum(Time*, Time*);
void showTime(Time);
int main(int argc, char* argv[])
{
    // 구조체 vs 배열
    // struct(구조체) 값 형식
    // 함수는 원본이 아닌 복사본을 대상으로 작업한다.
    
    // 구조체의 볼륨이 커질 경우에 구조체를 복사하는 시간이 걸리고
    // 메모리에 대한 요구가 높아진다.
    // -> 성능을 저하시킴.

    // 그래서 포인터를 쓰거나 참조를 전달한다.

    Time day1 = {5, 55};
    Time day2 = {3, 33};

    Time total = sum(&day1, &day2);

    cout << "Two days total time : ";
    showTime(total);
    
    return 0; 
}
Time sum(Time* t1, Time* t2)
{
    // 값에서 멤버로 접근할 때 : .
    // 주소에서 멤버로 접근할 때 : ->
    Time total;

    // 포인터를 통해 구조체의 멤버에 접근하는 경우 간접 연산자 -> 를 사용한다.
    total.mins = (t1->mins + t2->mins) % minsPerHr;
    total.hours = t1->hours + t2->hours +
        (t1->mins + t2->mins) / minsPerHr;

    return total;
}

void showTime(Time t1)
{
    cout << "Time : " << t1.hours << " min : " << t1.mins << endl;
}
