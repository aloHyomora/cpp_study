#pragma once
#include <iostream>
using namespace std;
class Node
{
	// typedef int T;
	using T = int;
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
public:
	T data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

//     [data]
// [Head] [Tail]
class List
{
public:
	List()
	{
		// dummy 추가
		_head = new Node(0);
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}
	~List()
	{
		Node* node = _head;
		while (node != nullptr) // 순차적으로 노드를 돌면서 delete
		{
			Node* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}
	
	//     [data]  -> [dummy] <-> [dummy]로 해두고 작업
	// [Head] [Tail]
	Node* AddAtHead(int data)
	{
		Node* node = new Node(data);

		Node* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}
	
	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);

		Node* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if(node == _tail) return nullptr;

		for (int i = 0; i < index; i++)
		{
			if(node == _tail->prev) return nullptr;
			
			node = node->next;
		}
		return node;
	}
	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);

		Node* prevNode = posNode->prev;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
		
	}
	Node* Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}
	// [dummy] <->[1]<->[2]<->[3]<-> [dummy]로 해두고 작업
	void Print()
	{
		Node* node = _head->next;
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};
