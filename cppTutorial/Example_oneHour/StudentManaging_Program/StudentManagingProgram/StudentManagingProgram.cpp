#include <iostream>
#include "Student.h"
#include "StudentList.h"
int main()
{    
    StudentList list;

    // 학생 추가
    Student student1("John Doe", 12345);
    student1.addGrade({ 95, 91, 97, 93, 95 });
    student1.addGrade({ 95, 91, 97, 93, 95 });
    list.addStudent(student1);

    Student student2("Jane Smith", 54321);
    student2.addGrade({ 95, 91, 97, 93, 95 });
    student2.addGrade({ 95, 91, 97, 93, 95 });
    list.addStudent(student2);

    // 모든 학생 정보 출력
    std::cout << "All students:" << std::endl;
    list.printAllStudents();

    // 특정 학생 찾기
    Student* foundStudent = list.getStudent(12345);
    if (foundStudent) {
        std::cout << "Found student:" << std::endl;
        foundStudent->printStudentInfo();
    }

    // 학생 삭제
    list.deleteStudent(54321);
    std::cout << "After deletion:" << std::endl;
    list.printAllStudents();

    return 0;
}
