#include <iostream>

using namespace std;

class StrAdd
{
public:
    StrAdd(){
        std::cout << "Initialize" << std::endl;
    }
    ~StrAdd(){
        std::cout << "Clean up" << std::endl;
    }
};

StrAdd s;//created -> hello -> killed

int main()
{
    std::cout << "Hello, world!\n";
}


