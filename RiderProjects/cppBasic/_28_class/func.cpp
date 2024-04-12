#include "Stock.h"

void Stock::acquire(string co, int n, float price)
{
    name = co;
    shares = n;
    share_val = price;
    set_total();
}
void Stock::buy(int n, float price)
{
    shares += n;
    share_val = price;
    set_total();
}
void Stock::sell(int n, float price)
{
    shares -= n;
    share_val = price;
    set_total();
}
void Stock::update(float price)
{
    share_val = price;
    set_total();
}
void Stock::show()
{
    cout << name << " Company" << endl;
    cout << "stock num : " << shares << endl;
    cout << "stock price : " << share_val << endl;
    cout << "stock total price : " << total_val << endl;
}

// 사용 범위 결정 연산자 :: => 이 함수에 포함된 함수이다를 알려줌.
// 생성자
Stock::Stock(string name, int n, int price)
{
    cout << "Create class (parameter)\n";
    this->name = name;
    shares = n;
    share_val = price;
    set_total();
}
Stock::Stock()
{
    cout << "Create class\n";
    this->name = "";
    shares = 0;
    share_val = 0;
    set_total();
}
// 파괴자
Stock::~Stock()
{
    cout << name << "Destroy class\n";
}