// queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>

template<typename T, typename Predicate = less<T>>
class PriorityQueue {
public:
	// 시간복잡도 : 0(longN) 트리의 높이에 의존적이기 때문..	
	void push(Const T& data) {
		// 우선 힙 구조부터 맞춘다.
		m_heap.push_back(data);

		// 도장깨기 시작
		int now = static_cast<int>(m_heap.size()) - 1;

		// 루트 노드까지
		while (now > 0)
		{
			// 부모 노드와 비교해서 더 작으면 패배
			int next = (now - 1) / 2;
			if (m_heap[now] < m_heap[next])  // (m_prdedicate(m_heap[next], m_heap[now])로 비교
				break;

			// 데이터 교환 (부모를 끌어내림)
			::swap(m_heap[now], m_heap[next]);
			now = next;
		}
	}
	// 0(logN)
	void pop() {
		m_heap[0] = m_heap.back(); // back은 맨 마지막 데이터를 의미, 그걸 root에 대입
		m_heap.pop_back(); // 원래 맨 마지막 데이터 제거

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// 리프에 도달한 경우
			if (left >= (int)m_heap.size())
				break;

			int next = now;

			// 왼쪽 비교 (나랑 왼쪽을 비교)
			if (m_heap[next] < m_heap[left])
				next = left;

			// 왼쪽과 오른쪽의 승자를 나랑 비교			
			if (right < m_heap.size() && m_heap[next] < m_heap[right])
				next = right;

			// 왼쪽/오른쪽이 둘 다 현재값 보다 작은 경우
			if (next == now)
				break;

			::swap(m_heap[now], m_heap[next]);
			now = next;
		}
	}
	// 0(1)
	T& top() {
		// 가장 우월한 값
		return m_heap[0];
	}
	// 0(1)
	bool empty() {
		return m_heap.empty();
	}
private:
	vector<T> m_heap;
	Predicate m_predicate;
};

int main()
{
	vector<int> v;

	PriorityQueue<int> pq;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(50);
	pq.push(40);

	// 가장 큰 수를 골라야 한다?
	// [][][][][][][][]
	// 1. 정렬 0(NlogN)
	// 2. 0(N)
	
	// 기준을 정해서 하나를 구할 때 유용하다.
	// 힙 트리 개념
	
	// == 이진 트리 : 각 노드가 최대 두 개의 자식을 가지는 트리
	// ==== 이진 검색 트리 특징 : 1. 왼쪽을 타고 가면 현재 값보다 작다. 
	// ---- 이진 검색 트리 특징 : 2. 오른쪽을 타고 가면 현재 값보다 크다
	// 무식하게 추가하면 한쪽으로 트리가 기울어져 균형이 깨진다.
	// 균형을 유지하는 것이 과제 (AVL, Red-Black)

	// -- 힙 트리 특징
	// ==== 힙 트리 1법칙 : [부모 노드]가 가진 값은 항상 [자식 노드]가 가진 값보다 크다
	// ==== 힙 트리 2법칙 : 노드의 총 개수를 알면, 트리 구조는 무조건 확정할 수 있다.
	// vector<int> heap(5)로도 표현 가능
	// i번 노드의 왼쪽 자식은 2 x i + 1번
	// i번 노드의 오른쪽 자식은 2 x i + 2번
	// i번 노드의 부모는 (i - 1) / 2번


	
	
}