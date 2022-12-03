#include <iostream>
using namespace std;

class Base
{
public:
    virtual void iam() { cout << "Base" << endl; }
};

class Son : public Base
{
public:
    void iam() { cout << "Son" << endl; }
};

class Dau : public Base
{
public:
    void iam() { cout << "Dau" << endl; }
};


int main()
{
    Base b;
    Son son;
    Dau dau;

    b.iam();
    son.iam();
    dau.iam();

    Base* p;
    p = &b;
    p->iam();
    p = &son;
    p->iam();
    p = &dau;
    p->iam();
}
