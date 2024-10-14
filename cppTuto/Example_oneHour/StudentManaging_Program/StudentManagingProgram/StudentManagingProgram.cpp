#include <iostream>
#include "Student.h"

int main()
{
    Student student1("김정효", 19);

    student1.addGrade({ 95, 91, 97, 93, 95 });
    student1.addGrade({ 95, 91, 67, 63, 95 });
    student1.updateGrade(0, KOREAN, 100);

    student1.printStudentInfo();
}
