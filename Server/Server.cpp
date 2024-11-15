#include <iostream>
using namespace std;

#include <thread>

#include <vector>


// Code			: 
// Stack X
// Heap 0		: 코어가 공유해서 사용함.
// Data 0		: 코어가 공유해서 사용함.
// 싱글 쓰레드에서 동작하다가 멀티스레드로 넘어가면 문제가 터질 수 있다.

void HelloThread(int i) {
	while (true)
	{
		cout << "Hello Thread" << i << endl;
	}
}



int main()
{
	vector<thread> threads;

	for (int i = 0; i < 10; i++)
	{
		threads.push_back(thread(HelloThread, i));
	}

	cout << "Hello Main" << endl;

	for (thread& t : threads)
	{
		t.join();
	}

	std::thread t(HelloThread, 1); // t(HelloThread, 100) 과 같이 매개 변수도 넘겨줄 수 있다.
		
	// Thread가 끝날 때 까지 기다린다.
	if(t.joinable())
		t.join();	



}
