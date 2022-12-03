
#ifndef CLIONCPP_PRESTUDENT_H
#define CLIONCPP_PRESTUDENT_H

class Teacher;

class preStudent{
public:
    explicit preStudent(std::string name, Teacher *tea = nullptr)
            : m_name(std::move(name)) {
        s_teacher = tea;
    }
    std::string getName() const {
        return m_name;
    }

protected:
    std::string m_name;
    static Teacher *s_teacher;
};
Teacher *preStudent::s_teacher = nullptr;

#endif //CLIONCPP_PRESTUDENT_H
