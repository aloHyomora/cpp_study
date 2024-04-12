#include <iostream>
#ifndef TIMEH
#define TIMEH

class Time
{
private:
	int hous;
	int mins;
public:
	Time();
	Time(int, int);
	~Time();

	void addHours(int);
	void addMins(int);
	Time operator+(Time&);
	void show();
	// 멤버 함수가 아니다.
	// 멤버 함수와 동등한 접근 권한을 가짐. 이를 통해 private 멤버 변수에 접근 가능하다.  
	friend Time operator*(int n, Time& t)
	{
		return t * n;
	};
	Time operator*(int);

	// 프렌드, ostream에 있는 객체를 리턴 ostream, Time을 받음.
	friend std::ostream& operator<<(std::ostream&, Time&);
};

#endif
