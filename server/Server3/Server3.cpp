#include <iostream>
using namespace std;

#include <vector>
#include <Windows.h>
#include <atomic>
#include <mutex>

int sum = 0;

atomic<int> a;
atomic<int> b;


// Mutual Exclusive (상호배타적)
// lock : 비행기의 화장실 한 명만 들어갈 수 있다. 들어가서 자물쇠를 잠궈버린다.
mutex m;

vector<int> v;	// 동적 배열이다. 힙 영역에 위치한다.
// vector라는 클래스 자체는 전역 변수

void Push() {
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
}
void PushLock() {
	for (int i = 0; i < 10000; i++)
	{
		m.lock();
		v.push_back(i);
		m.unlock();
	}
}
void PushLockGuard() { // 코드 영역 벗어나면 바로 소멸, 소멸자에서 unlock 호출
	for (int i = 0; i < 10000; i++)
	{
		LockGuard<mutex> lockGuard(m);

		v.push_back(i);
		
		if (i == 5000) break;
	}
}

// RAII
template<typename T>
class LockGuard {
public:
	LockGuard(T& m) : _mutex(m)
	{
		_mutex.lock();
	}
	~LockGuard() {
		_mutex.unlock();
	}
private:
	T& _mutex;
};
int main()
{
	//v.reserve(100000); // capacity 늘려주기 ->> 이상한 값이 출력된다. 하나의 주소를 여러 곳에서 쓰
	//thread t1(Push);
	//thread t2(Push);

	//t1.join();
	//t2.join();


	//cout << v.size() << endl;
	//
	//// 실행 결과 : 힙 영역에 동시다발적으로 제한 없이 접근해서 크래시가 발생한다.

	// 자물쇠를 먼저 잠구는 애가 승리한다.
	thread t1(Push);
	thread t2(Push);
	thread t3(Push);

	t1.join();
	t2.join();
	t3.join();

	cout << v.size() << endl;
}
