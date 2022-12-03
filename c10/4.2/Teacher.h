//
// Created by liucxi on 2022/5/13.
//

#ifndef UNTITLED_TEACHER_H
#define UNTITLED_TEACHER_H

#include <string>
#include <iostream>

#include "preStudent.h"

class Teacher {
public:
    explicit Teacher(std::string name, preStudent *stu = nullptr)
            : m_name(std::move(name)) {
        s_student = stu;
    }

    static void SetStudent(preStudent *stu) {
        s_student = stu;
    }

    std::string getName() const {
        return m_name;
    }

    void getInfo() const {
        std::cout << "I'm a teacher, my name is : " << m_name
                   << " and my student's name is : " << s_student->getName()
                  << std::endl;
    }

private:
    std::string m_name;
    static preStudent *s_student;
};

preStudent *Teacher::s_student = nullptr;

#endif //UNTITLED_TEACHER_H
