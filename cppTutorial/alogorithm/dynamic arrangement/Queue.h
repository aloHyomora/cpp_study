#pragma once

#include "Vector.h"

// [front/back][][][][][][][][][][]
// [front][][][back][][][][][][][]
// ---�����Ϳ���----
template<typename T>
class Queue
{
public:
	Queue() {
		m_container.resize(100);
	}
	~Queue(){}

	void push(const T& value) {
		// �� á���� üũ
		if (m_size == m_container.size())
		{

		}

		m_container[m_back] = value;
		m_back = (m_back + 1) % m_container.size(); // vector�� ������ �Ѿ ���, �ٽ� ������ back�� �ε����� 0���� ����
		m_size++;
	}

	void pop(){
		m_front = (m_front + 1);
		m_size--;
	}


	T& front() {

	}

	bool  empty() { return m_size == 0; }
	int	  size() { return m_size; }
private:
	Vector<T> m_container;

	int m_front = 0;
	int m_back = 0;
	int m_size = 0;

};

