#pragma once
#include <assert.h>

class Array
{
	using T = int;

public:
	explicit Array(int capacity = 100) : m_capacity(capacity) {
		m_buffer = new T[capacity];
	}
	
	~Array() {
		delete[] m_buffer;
	}

	void PushBack(const T& data) {
		// TODO
		if (m_size == m_capacity) return;

		m_buffer[m_size] = data;
		m_size++;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < m_size);
		return m_buffer[index];
	}

	int GetSize() { return m_size; }
	int GetCapacity() { return m_capacity; }

private:
	T* m_buffer = nullptr;
	int m_size = 0;
	int m_capacity = 0;
};

