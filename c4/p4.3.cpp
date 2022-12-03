#include <iostream>

using namespace std;

int main()
{
    //fundamental types
    cout << "bool = " << sizeof(bool) << endl;

    cout << "char = " << sizeof(char) << endl;
    cout << "unsigned char = " << sizeof(unsigned char) << endl;

    cout << "short = " << sizeof(short) << endl;
    cout << "unsigned short = " << sizeof(unsigned short) << endl;
    cout << "int = " << sizeof(int) << endl;
    cout << "unsigned int = " << sizeof(unsigned int) << endl;
    cout << "long = " << sizeof(long) << endl;
    cout << "unsigned long = " << sizeof(unsigned long) << endl;
    cout << "long long = " << sizeof(long long) << endl;
    cout << "unsigned long long = " << sizeof(unsigned long long) << endl;

    cout << "float = " << sizeof(float) << endl;
    cout << "double = " << sizeof(double) << endl;
    cout << "long double = " << sizeof(long double) << endl << endl;

    //pointer types
    cout << "char* = " << sizeof(char *) << endl;
    cout << "int* = " << sizeof(int *) << endl;
    cout << "double* = " << sizeof(double *) << endl << endl;

    //enumerations
    enum e1 { marisa, reimu };
    enum e2 { ojj, ojjoo, ojj11111 };
    enum e3 { ore, wa ,jojo=1145141919810 ,da ,yadaze ,ngldy=255 };
    std::cout << "Enum1 = " << sizeof(e1) << endl;
    std::cout << "Enum2 = " << sizeof(e2) << endl;
    std::cout << "Enum2 = " << sizeof(e3) << endl;

    return 0;
}
