#pragma once

#include <iostream>
using namespace std;

#include "Student.h"

// ���� ����Ʈ�� ��带 ��Ÿ���� ����ü
struct Node {
	Student student; // �л� ��ü
	Node* next; // ���� ��带 ����Ű�� ������

	// ��� ������
	Node(const Student& s) : student(s), next(nullptr) {}
};

class StudentList
{
private:
	Node* m_head;
	
public:
	// ������
	StudentList() : m_head(nullptr) {}
	// �Ҹ��� : ��� ��带 �����Ѵ�.
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

	// ���ο� �л� �߰�
	void addStudent(const Student& newStudent) {
		Node* newNode = new Node(newStudent);

		// ���Լ���(LIFO)
		// �� �л��� ����Ʈ�� ù ��°�� �߰�
		// �� �л��� ������ ���� ���
		newNode->next = m_head;

		// �ٽ� ù ����� ��
		m_head = newNode;
	}
	// �й��� �������� �л� ã��
	Student* getStudent(int id) {
		Node* current = m_head;
		while (current != nullptr)
		{
			if (current->student.getId() == id) {
				return &(current->student);
			}
		}
		// �л��� ã�� ���� ���  nullptr ��ȯ
		return nullptr; 
	}
	// �й��� �������� �л� ����

	// ��� �л� ���� ���
	void printAllStudents() const {
		Node* current = m_head;
		while (current != nullptr)
		{
			current->student.printStudentInfo();
			current = current->next;
		}
	}
};


//Node ����ü : ���� ����Ʈ���� �� �л� ��ü�� ���� ���μ� �����մϴ�.�� ���� Student ��ü�� ���� ��带 ����Ű�� next �����͸� �����ϴ�.
//StudentList Ŭ���� :
//head: ����Ʈ�� ù ��° ��带 ����Ű�� �������Դϴ�.
//addStudent() : ���ο� �л��� ����Ʈ�� �պκп� �߰��մϴ�.
//findStudent() : �й��� �������� �л��� ã�� ��ȯ�մϴ�.�л��� ã�� ���ϸ� nullptr�� ��ȯ�մϴ�.
//deleteStudent() : �й��� �������� �л��� ã�� �����մϴ�.
//printAllStudents() : ����Ʈ�� �ִ� ��� �л��� ������ ����մϴ�.
//Student Ŭ���� : �л��� ������ �����ϰ�, ���� �߰�, ���� ��� ��� ���� ó���մϴ�.
