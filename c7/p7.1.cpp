#include <iostream>

using namespace std;

void f1(char* c, int &i);
typedef void (*PF)(char*, int&);

void f2(PF a1);

PF f3();

PF f4(PF p)
{
    return p;
}

int main(int argc, char* argv[])
{
}
