#include <iostream>

using namespace std;

//The problem's meaning is not clear.
//I'm trying not to use structure's init function.
//So this program's logic is bad.

struct Date {
//init function
//    Date(int y, int m, int d)
//    {
//        year = y;
//        month = m;
//        day = d;
//    }
    int y;
    int m;
    int d;
};

Date iniDate(int y, int m, int d){
    return {y, m, d};
}

Date readDate()
{
    int y, m, d;
    cin >> y >> m >> d;
    return iniDate(y,m,d);//crazy step
}

void writeDate(Date date)
{
    cout << date.y << " " << date.m << " " << date.d << endl;
}

int main()
{
    cout << "Input date:";
    Date d1 = readDate();
    cout << "The d1: ";
    writeDate(d);
    return 0;
}
