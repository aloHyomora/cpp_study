#pragma once

using namespace std;
#include <iostream>
#include <string>
#include <vector>
// 과목을 enum으로 정의
enum Subject {
	KOREAN = 0,
	MATH,
	HISTORY,
	SCIENCE,
	ENGLISH,
	SUBJECT_COUNT // 과목의 총 개수 (5)
};
class Student
{

public:
	 string m_name;
	 int m_studentId;

	 // 23-1, 23-2, 24-1, 24-2 데이터만 가짐
	 vector<vector<int>> m_grades;
	
public:
	// 생성자
	Student(const string& name, int id) : m_name(name), m_studentId(id)
	{
		
	}

	// 학번을 반환
	int getId() const { return m_studentId; }
	// 새로운 분기의 성적 추가
	void addGrade(vector<int> grades) {
		m_grades.push_back(grades);
	}
	// 특정 분기의 특정 성적을 수정하는 함수.
	void updateGrade(int quarterIndex, Subject subject, int newGrade) {
		if (quarterIndex >= 0 && quarterIndex < m_grades.size()) {
			m_grades[quarterIndex][static_cast<size_t>(subject)] = newGrade;  //[quarterIndex][static_cast<size_t>(subject)] = newGrade;  // 과목 인덱스로 성적 수정
		}
		else {
			cout << "Invalid grade index." << endl;
		}
	}
	// 성적의 평균을 계산해 반환하는 함수.
	double calculateAverage(int quaterIndex) const {
		if (m_grades.empty()) return 0;
		double totalScore = 0;

		for (int i = 0; i < SUBJECT_COUNT; i++)
		{
			totalScore += static_cast<double>(m_grades[quaterIndex][i]);
		}
		
		return totalScore / SUBJECT_COUNT;
	}
	// 학생 정보와 성적을 출력하는 함수.
	void printStudentInfo() {		
		cout << "=========================." << endl;
		cout << "이름 : " << m_name << endl;
		cout << "학번 : " << m_studentId << endl;
		cout << "시험 본 횟수(데이터 개수) : " << m_grades.size() << endl;
		for (int quaterIndex = 0; quaterIndex < m_grades.size(); quaterIndex++)
		{
			cout << "*** " << quaterIndex << "번째 시험 *** 평균 " << calculateAverage(quaterIndex) << "점" << endl;
			cout << "-> 국어 : " <<  m_grades[quaterIndex][KOREAN] << "점 / 100점" << endl;
			cout << "-> 수학 : " << m_grades[quaterIndex][MATH] << "점 / 100점" << endl;
			cout << "-> 사회 : " << m_grades[quaterIndex][HISTORY] << "점 / 100점" << endl;
			cout << "-> 과학 : " << m_grades[quaterIndex][SCIENCE] << "점 / 100점" << endl;
			cout << "-> 영어 : " << m_grades[quaterIndex][ENGLISH] << "점 / 100점" << endl;
		}
		cout << "=========================." << endl;
	}
};


