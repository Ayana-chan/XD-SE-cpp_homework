
#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include <utility>
#include "Teacher.h"

class Student: public preStudent {
public:
    explicit Student(std::string name, Teacher *tea = nullptr):preStudent(std::move(name), tea){}
    static void SetTeacher(Teacher *tea) {
        s_teacher = tea;
    }
    void getInfo() const {
        std::cout << "I'm a student, my name is : " << m_name
                  << " and my teacher's name is : " << s_teacher->getName()
                  << std::endl;
    }
};

#endif //UNTITLED_STUDENT_H
