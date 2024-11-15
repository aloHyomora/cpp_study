#include <iostream>
using namespace std;

#include <thread>

#include <vector>

#include <Windows.h>

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


int buffer[10000][10000];


int x = 0;
int y = 0;
int r1 = 0;
int r2 = 0;

volatile bool ready = false; // volatile -> 컴파일러야 너 멋대로 판단하지마. ex) ready == false를 그냥 false로 인식

void Thread1() {
	while (ready == false)
	{

	}
	y = 1;
	r1 = x;
}

void Thread2() {
	while (ready == false)	{}

	x = 1;
	r2 = y;
	
}
void Thread3() {
	while (ready == false)
	{

	}cout << "YYYY" << endl;
}
int main()
{
	thread t3(Thread3);
	this_thread::sleep_for(1s);
	ready = true;

	t3.join();
	/*int count = 0;
	while (true)
	{
		count++;

		x = y = r1 = r2 = 0;

		thread t1(Thread1);
		thread t2(Thread2);

		ready = true;

		t1.join();
		t2.join();

		if (r1 == 0 && r2 == 0)
			break;
	}
	cout << count << endl;*/
	/*::memset(buffer, 0, sizeof(buffer));

	{
		auto start = GetTickCount64();
		
		__int64 sum = 0;

		for (int i = 0; i < 10000; i++)
			for (int j = 0; j < 10000; j++)
				sum += buffer[i][j];

		auto end = GetTickCount64();

		cout << "Elapsed Tcik " << (end - start) << endl;
	}

	{
		auto start = GetTickCount64();

		__int64 sum = 0;

		for (int i = 0; i < 10000; i++)
			for (int j = 0; j < 10000; j++)
				sum += buffer[j][i];

		auto end = GetTickCount64();

		cout << "Elapsed Tcik " << (end - start) << endl;
	}*/


	//vector<thread> threads;

	//for (int i = 0; i < 10; i++)
	//{
	//	threads.push_back(thread(HelloThread, i));
	//}

	//cout << "Hello Main" << endl;

	//for (thread& t : threads)
	//{
	//	t.join();
	//}

	//std::thread t(HelloThread, 1); // t(HelloThread, 100) 과 같이 매개 변수도 넘겨줄 수 있다.
	//	
	//// Thread가 끝날 때 까지 기다린다.
	//if(t.joinable())
	//	t.join();	



}
