#include "Time.h"


Time::Time()
{
	hous = mins = 0;
}

Time::Time(int h, int m)
{
	hous = h;
	mins = m;
}
Time::~Time()
{
	
}
void Time::addHours(int h)
{
	hous += h;
}
void Time::addMins(int m)
{
	mins += m;
	hous += mins / 60;
	mins %= 60;
}
Time Time::operator+(Time& t)
{
	Time sum;
	sum.hous = hous + t.hous;
	sum.mins = mins + t.mins;
	sum.hous += sum.mins / 60;
	sum.mins %= 60;

	return sum;
}
void Time::show()
{
	std::cout << "Hours : " << hous << std::endl; 
	std::cout << "Mins : " << mins << std::endl; 
}

Time Time::operator*(int n)
{
	Time result;
	long resultMin = hous * n * 60 + mins * n;
	result.hous = resultMin / 60;
	result.mins = resultMin % 60;
	return result;
}
std::ostream& operator<<(std::ostream& os, Time& t)
{
	os << t.hous << " hours " << t.mins << " min";
	return os;

	// << 연산자는 좌항의 값으로 ostream 객체를 요구하고 있기 때문에 리턴형이 os의 참조라는 것에 주목해야 한다.
}