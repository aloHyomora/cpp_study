#ifndef STOCK
#define STOCK
#include <iostream>
using namespace std;

class Stock
{
private:
    // private에 선언된 멤버의 값을 변경하기 위해선, public에 선언된 함수를 통해서 변경해야 한다.
    // 데이터 은닉, 데이터에 직접 접근하지 못하게 차단, 추상화의 예시 중 하나
    string name;
    int shares;
    float share_val;
    double total_val;
    void set_total() {total_val = shares * share_val;}
public:
    void acquire(string, int, float);
    void buy(int, float);
    void sell(int, float);
    void update(float);
    void show();
    Stock(string, int, int);
    Stock();
    ~Stock();
};
#endif