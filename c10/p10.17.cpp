#include <iostream>

using namespace std;

class Student;

class Teacher
{
public:
    char *Tname;
    static Student * s;
    Teacher(Student *stu,char* name){s=stu;Tname=name;}
    void change(Student *st){s=st;}
    void print();
};

class Student
{
public:
    char *Sname;
    static Teacher *t;
    Student(Teacher *tea,char *name){t=tea;Sname=name;}
    void print();
};

void Teacher::print()
{
    cout<<"the teacher's name:"<<Tname<<endl
        <<"his student's name:"<<s->Sname<<endl;
}

void Student::print()
{
    cout<<"the student's name:"<<Sname<<endl
        <<"his teacher's name:"<<t->Tname<<endl;
}

Student* Teacher::s=NULL;
Teacher* Student::t=NULL;

// 测试函数
int main()
{
    char name1[10], name2[10];
    cout<<"input teacher's name:";
    cin>>name1;
    Teacher t(NULL,name1);
    cout<<"input student's name:";
    cin>>name2;
    Student s(&t,name2);
    t.change(&s);
    s.print();
    t.print();
}