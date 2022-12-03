/**
 * @author liucxi
 * @date 2022/05/13
 */
#include <iostream>
#include "Student.h"

int main() {
    std::string name1, name2;

    std::cout << "input teacher's name:";
    std::cin >> name1;
    // 先定义的 Teacher 对象无法确定第二参数，因为 Student 还未定义
    Teacher t(name1, nullptr);

    std::cout << "input student's name:";
    std::cin >> name2;
    // 后定义的 Student 对象可以确定第二参数
    Student s(name2, &t);

    // 为 Teacher 对象中的 Student 数据成员赋值
    Teacher::SetStudent(&s);

    s.getInfo();
    t.getInfo();

    system("pause");
    return 0;
}
