#pragma once
#include "Vector.h"

template<typename T>
class Stack
{
public: 

	void push(const T& value) {
		m_container.push_back(value);
	}
	void pop() {
		m_container.pop_back();
	}

	T& top(){
		return m_container.back();
	}

	bool empty() { return size() > 0;}
	int size() { return m_container.size(); }
private:
	Vector<T> m_container;
};

