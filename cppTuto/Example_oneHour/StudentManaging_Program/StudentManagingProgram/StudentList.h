#pragma once

#include <iostream>
using namespace std;

#include "Student.h"

// 연결 리스트의 노드를 나타내는 구조체
struct Node {
	Student student; // 학생 객체
	Node* next; // 다음 노드를 가리키는 포인터

	// 노드 생성자
	Node(const Student& s) : student(s), next(nullptr) {}
};

class StudentList
{
private:
	Node* m_head;
	
public:
	// 생성자
	StudentList() : m_head(nullptr) {}
	// 소멸자 : 모든 노드를 해제한다.
	~StudentList()
	{
		Node* current = m_head;

		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	// 새로운 학생 추가
	void addStudent(const Student& newStudent) {
		Node* newNode = new Node(newStudent);

		// 후입선출(LIFO)
		// 새 학생을 리스트의 첫 번째에 추가
		// 새 학생의 다음은 기존 헤드
		newNode->next = m_head;

		// 다시 첫 번재는 나
		m_head = newNode;
	}
	// 학번을 기준으로 학생 찾기
	Student* getStudent(int id) {
		Node* current = m_head;
		while (current != nullptr)
		{
			if (current->student.getId() == id) {
				return &(current->student);
			}
		}
		// 학생을 찾지 못한 경우  nullptr 반환
		return nullptr; 
	}
	// 학번을 기준으로 학생 삭제

	// 모든 학생 정보 출력
	void printAllStudents() const {
		Node* current = m_head;
		while (current != nullptr)
		{
			current->student.printStudentInfo();
			current = current->next;
		}
	}
};


//Node 구조체 : 연결 리스트에서 각 학생 객체를 노드로 감싸서 관리합니다.각 노드는 Student 객체와 다음 노드를 가리키는 next 포인터를 가집니다.
//StudentList 클래스 :
//head: 리스트의 첫 번째 노드를 가리키는 포인터입니다.
//addStudent() : 새로운 학생을 리스트의 앞부분에 추가합니다.
//findStudent() : 학번을 기준으로 학생을 찾아 반환합니다.학생을 찾지 못하면 nullptr을 반환합니다.
//deleteStudent() : 학번을 기준으로 학생을 찾아 삭제합니다.
//printAllStudents() : 리스트에 있는 모든 학생의 정보를 출력합니다.
//Student 클래스 : 학생의 정보를 저장하고, 성적 추가, 성적 평균 계산 등을 처리합니다.
