#pragma once
#include <iostream>
using namespace std;
class Node {
	// 별칭
	//typedef int T;
	using T = int;
public:
	Node(int data) : m_data(data), prev(nullptr), next(nullptr) {}
public:
	T m_data; // 나중에 템플릿으로 바꿀 거임.
	Node* prev;
	Node* next;
};

class List {
public:
	List() {
		m_head = new Node(0);
		m_tail = new Node(0);
		m_head->next = m_tail;
		m_tail->prev = m_head;
	}
	~List() {
		Node* node = m_head;
		while (node != nullptr)
		{
			Node* deleteNode = node;
			// 다음 노드를 꺼내온다. (아래 코드와 동일)
			node = node->next;

			/*Node* nextNode = node->next;
			node = nextNode;*/

			delete deleteNode;
		}
	}

	void Print() {
		Node* node = m_head->next;
		while (node != m_tail)
		{
			cout << node->m_data << " ";
			node = node->next;
		}
		cout << endl;
	}

	//		[new Node]
	// [dummy] <-> [next Node] <-> [2] <-> [3] <-> [dummy]
	Node* AddAtHead(int data) {
		Node* newNode = new Node(data);
		Node* nextNode = m_head->next;
		
		newNode->next = nextNode;
		nextNode->prev = newNode;

		m_head->next = newNode;
		newNode->prev = m_head;

		return newNode;
	}
	Node* AddAtTail(int data) {
		Node* newNode = new Node(data);
		Node* prevNode = m_tail->prev;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		m_tail->prev = newNode;
		newNode->next = m_tail;

		return newNode;
	}

	Node* GetNode(int index) {
		Node* node = m_head->next;
		if (node == m_tail) return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == m_tail->prev)
				break;

			node = node->next;
		}
						
		return node;
	}

	// 삽입 위치를 알고 있을 때만 속도가 빠르다.
	void Insert(Node* posNode, int data) {
		Node* node = new Node(data);

		Node* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}
	void Remove(Node* node) {
		Node* prevNode = node->prev;
		Node* nextNode = node->next;
		
		prevNode->next = nextNode;
		nextNode->prev = prevNode;		
	}
private:
	Node* m_head = nullptr;
	Node* m_tail = nullptr;
};

