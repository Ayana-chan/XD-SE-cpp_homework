#include <iostream>
#include <string>

using namespace std;

int main()
{
    //1st
    const char* months1[12] = {"Jan","Feb","Mar","Apr","May","Jun",
                                "Jul","Aug","Sep","Oct","Nov","Dec"};
    const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cout << "1st" << endl;
    for(int i = 0; i < 12; i++){
        cout << months1[i] << " : " << days[i] << endl;
    }

    //2nd
    typedef struct m_d
    {
        const char *name;
        int days;
    }m_d;
    m_d mdArray[12] = {{"Jan", 31},{"Feb", 28},{"Mar", 31},{"Apr", 30},
                        {"May", 31},{"Jun", 30},{"Jul", 31},{"Aug", 31},
                        {"Sep", 30},{"Oct", 31},{"Nov", 30},{"Dec", 31}};
    cout << endl << "2nd" << endl;
    for(int i = 0; i < 12; i++){
        cout << mdArray[i].name << " : " << mdArray[i].days << endl;
    }

    return 0;
}
