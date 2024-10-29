#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
#include <queue>

#pragma region BasicSort
// 버블 정렬 0(N^2)
// 왼쪽부터 오른쪽으로 버블이 이동하면서 바꿔가는 (like 파도타기)
// 1 5 3 4 2
// 1 3 5 4 2
// 1 3 4 5 2
// 1 3 4 2 5
void BubbleSort(vector<int>& v) {
	const int n = v.size();

	// 0(N^2)
	// n-1이 마지막 두번 째 
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;

				// swap(v[j],v[j+1])
			}
		}
	}	
}

// 선택 정렬 0(N^2)
// 한 번 스캔 후 제일 작은 건 누구? -> 너가 1번, 그 다음 작은 건?
// 1 5 3 4 2
void SelectionSort(vector<int>& v) {
	const int n = v.size();

	for (int j = 0; j < n-1; j++)
	{
		int bestIdx = j;

		for (int i = j+1; i < n; i++)
		{
			if (v[i] < v[bestIdx])
				bestIdx = i;
		}

		if (j != bestIdx)
			swap(v[j], v[bestIdx]);
	}
	
}

// 힙 정렬 0(NlogN)
void HeapSort(vector<int>& v) {
	priority_queue<int, vector<int>, greater<int>> pq;

	// 0(NlogN)
	for (int num : v) // N
		pq.push(num); // logN

	// 우선순위 큐는 log n
	// 0(NlogN)
	while (pq.empty() == false) // N
	{
		v.push_back(pq.top()); // 0(1)
		pq.pop();// 0(logN)
	}
}
#pragma endregion
#pragma region MergeSort
// 분할 정복 (Divide and Conquer)
// - 분할(Divide)	문제를 더 단순하게 분할한다.
// - 정복(conquer)	분할도니 문제를 해결
// - 결합(combine)	결과를 취합하여 마무리
// 분할
// [3][K][7][2][J][4][8][9]				<< 8개*1
// [3][K][7][2]	[J][4][8][9]			<< 4개*2
// [3][K]	[7][2]	[J][4]	[8][9]		<< 2개*4
// [3]	[K]	[7]	[2]	[J]	[4]	[8] [9]		<< 1개*8
// 
// 정복, 결합
// [3][K]	[2][7]	[4][J]	[8][9]	<- 두 개 묶음은 이미 정렬된 상태,, 3과 2 중에 작은 2,
// [2][3][7][K]	[4][8][9][J]
void MergeResult(vector<int>& v, int left, int mid, int right);
// 0(NlogN)
void MergeSort(vector<int>& v, int left, int right) {
	// left, right로 영역을 집어서 관리

	if (left >= right) // 더이상 분할을 못하는 상태
		return;

	int mid = (left + right) / 2;

	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);

}
void MergeResult(vector<int>& v, int left, int mid, int right) {

	// 인덱스 시작 부분
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx]) {
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else {
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}
#pragma endregion
int main()
{
	vector<int> v{ 1,3,4,5,2 };

	//BubbleSort(v);
	//SelectionSort(v);
	//HeapSort(v);

	MergeSort(v, 0, v.size() - 1);
}
