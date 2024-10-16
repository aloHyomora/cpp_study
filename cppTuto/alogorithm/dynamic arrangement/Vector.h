#pragma once
#include <assert.h>

class Vector
{
	using T = Pos;

public:
	explicit Vector(){
		
	}

	~Vector() {
		if(m_buffer)
			delete[] m_buffer;
	}

	void PushBack(const T& data) {
		// TODO : 
		if (m_size == m_capacity) {
			// 증설 작업
			int newCapacity = static_cast<int>(m_capacity * 1.5);
			if (newCapacity == m_capacity) newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		m_buffer[m_size] = data;

		// 데이터 개수 증가
		m_size++;
	}

	void Clear() {
		if (m_buffer)
		{
			delete[] m_buffer;
			m_buffer = new T[m_capacity];
		}
	}
	void pop_back() {

	}
	T& back() {

	}
	void reserve(int capacity) {
		if (m_capacity >= capacity) return;

		m_capacity = capacity;

		T* newData = new T[m_capacity];

		// 데이터 복사
		for (int i = 0; i < m_size; i++)
			newData[i] = m_buffer[i];

		if (m_buffer) delete m_buffer;

		m_buffer = newData;
	}

	T& operator[](int index) {
		assert(index >= 0 && index < m_size);
		return m_buffer[index];
	}

	int GetSize() { return m_size; }
	int GetCapacity() { return m_capacity; }

private:
	T*		m_buffer = nullptr;
	int		m_size = 0;
	int		m_capacity = 0;
};

