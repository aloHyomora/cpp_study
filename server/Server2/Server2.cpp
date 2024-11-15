#include <iostream>
using namespace std;
#include <vector>
#include <Windows.h>
#include <thread>


// Data
// Heap



int sum = 0; // Heap에 들어가니 공유되는 변수이다.
atomic<int> sum2 = 0;

void Add() {

	int i = 1; // 만약 i를 더하면 문제 없음. Stack에 데이터가 존재함.

	for (int i= 0; i < 1000000; i++)
	{
		// All or nothing -> 작업을 하거나 안 하거나 두 가지 상태뿐. 나 혼자 작업하겠다.
		// 훨씬 느리다.
		sum2++;


		// sum++;

		// 어셈블리 상에서 이렇게 표현됨. 연산이 끝나기 전의 값을 가져와서 +,-을 할 수 있다.
		/*int eax = sum;	
		eax = eax + 1;
		sum = eax;*/
	}
}
void Sub() {
	for (int i = 0; i < 1000000; i++)
	{
		sum2--;


		// sum--;

	}
}

int main()
{ 
	// int temp = sum;
	int temp = sum2.load(); // sum2 가져오기(atomic이라고 티내는 거임)

	// sum2 = 10;
	sum2.store(10); // sum2에 저장 (atomic이라고 티내는 거임)

	// int temp2 = sum2.exchange(10); // 10 이전에 무슨 값이 있었는지



	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();


	cout << sum << endl;
	// 실행 결과 0이 안 나옴
	// Heap 영역의 sum을 공유해서 사용함.
}
