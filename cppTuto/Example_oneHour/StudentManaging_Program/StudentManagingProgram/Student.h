#pragma once

using namespace std;
#include <iostream>
#include <string>
#include <vector>
// ������ enum���� ����
enum Subject {
	KOREAN = 0,
	MATH,
	HISTORY,
	SCIENCE,
	ENGLISH,
	SUBJECT_COUNT // ������ �� ���� (5)
};
class Student
{

public:
	 string m_name;
	 int m_studentId;

	 // 23-1, 23-2, 24-1, 24-2 �����͸� ����
	 vector<vector<int>> m_grades;
	
public:
	// ������
	Student(const string& name, int id) : m_name(name), m_studentId(id)
	{
		
	}

	// �й��� ��ȯ
	int getId() const { return m_studentId; }
	// ���ο� �б��� ���� �߰�
	void addGrade(vector<int> grades) {
		m_grades.push_back(grades);
	}
	// Ư�� �б��� Ư�� ������ �����ϴ� �Լ�.
	void updateGrade(int quarterIndex, Subject subject, int newGrade) {
		if (quarterIndex >= 0 && quarterIndex < m_grades.size()) {
			m_grades[quarterIndex][static_cast<size_t>(subject)] = newGrade;  //[quarterIndex][static_cast<size_t>(subject)] = newGrade;  // ���� �ε����� ���� ����
		}
		else {
			cout << "Invalid grade index." << endl;
		}
	}
	// ������ ����� ����� ��ȯ�ϴ� �Լ�.
	double calculateAverage(int quaterIndex) const {
		if (m_grades.empty()) return 0;
		double totalScore = 0;

		for (int i = 0; i < SUBJECT_COUNT; i++)
		{
			totalScore += static_cast<double>(m_grades[quaterIndex][i]);
		}
		
		return totalScore / SUBJECT_COUNT;
	}
	// �л� ������ ������ ����ϴ� �Լ�.
	void printStudentInfo() {		
		cout << "=========================." << endl;
		cout << "�̸� : " << m_name << endl;
		cout << "�й� : " << m_studentId << endl;
		cout << "���� �� Ƚ��(������ ����) : " << m_grades.size() << endl;
		for (int quaterIndex = 0; quaterIndex < m_grades.size(); quaterIndex++)
		{
			cout << "*** " << quaterIndex << "��° ���� *** ��� " << calculateAverage(quaterIndex) << "��" << endl;
			cout << "-> ���� : " <<  m_grades[quaterIndex][KOREAN] << "�� / 100��" << endl;
			cout << "-> ���� : " << m_grades[quaterIndex][MATH] << "�� / 100��" << endl;
			cout << "-> ��ȸ : " << m_grades[quaterIndex][HISTORY] << "�� / 100��" << endl;
			cout << "-> ���� : " << m_grades[quaterIndex][SCIENCE] << "�� / 100��" << endl;
			cout << "-> ���� : " << m_grades[quaterIndex][ENGLISH] << "�� / 100��" << endl;
		}
		cout << "=========================." << endl;
	}
};


