#include <iostream>

using namespace std;

class Date {
    friend ostream &operator<<(ostream &cout1,Date &d);
public:
//    enum Month{jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
    class Bad_Date{};//error
    Date(int yy=0, int mm=0, int dd=0);
    bool judgeLeapYear() const;//weather leap year (now)
    bool judgeLeapYear(int y) const;//weather leap year (certain)
    int getMaxDay() const;//get the max days' number  of the month (now)
    Date &addYear(int n);
    Date &addMonth(int n);
    Date &addDay(int n);
    static void setDefault(int yy,int mm,int dd);
private:
    int y,d;
    int m;
    static Date default_date;
};

Date Date::default_date=Date(1970,1,1);

ostream &operator<<(ostream &cout1,Date &d){
    cout1 << d.y << "-" << d.m << "-" << d.d << endl;
    return cout1;
}

Date::Date(int yy, int mm, int dd) {
    y = yy ? yy : default_date.y;
    m = mm ? mm : default_date.m;
    d = dd ? dd : default_date.d;
    //error
    bool yError = y==0;
    bool mError = m<1 || m>12;
    bool dError = d<1 || d>getMaxDay();
    if(yError || mError || dError){
        throw Bad_Date();
    }
}

bool Date::judgeLeapYear() const {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    return false;
}

bool Date::judgeLeapYear(int y) const{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    return false;
}

int Date::getMaxDay() const {
    int days[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (judgeLeapYear() && m == 2) return 29;
    return days[m-1];
}

Date& Date::addYear(int n) {
    if (this->m == 2 && this->d == 29 && judgeLeapYear(this->y + n)) {
        this->d = 1;
        this->m = 3;
    }
    if (this->y < 0 && this->y + n >= 0) {
        this->y++;
    }//year -1 jump to year 1
    this->y += n;
    return *this;
}

Date& Date::addMonth(int n) {
    addYear((this->m + n-1) / 12);
    this->m =(this->m + n-1) % 12+1;
    return *this;
}

Date& Date::addDay(int n) {
    this->d+=n;
    while (this->d > getMaxDay()) {
        this->d -= getMaxDay();
        addMonth(1);
    }
    return *this;
}

void Date::setDefault(int yy,int mm,int dd) {
    default_date.y=yy;
    default_date.m=mm;
    default_date.d=dd;
}


int main() {
    try {
        Date date = Date(2012, 2);

        cout << "4day\n";
        cout << date;
        date.addDay(4);
        cout << date;
        date.addDay(4);
        cout << date;
        date.addDay(4);
        cout << date;
        date.addDay(4);
        cout << date;
        cout << "80day\n";
        date.addDay(80);
        cout << date;
        date.addDay(80);
        cout << date;
        date.addDay(80);
        cout << date;
        date.addDay(80);
        cout << date;
        cout << "5month\n";
        date.addMonth(5);
        cout << date;
        date.addMonth(5);
        cout << date;
        date.addMonth(5);
        cout << date;
        date.addMonth(5);
        cout << date;
    } catch (Date::Bad_Date) {
        cerr << "Bad Date Error";
    }

    try {
        Date dateE(1650, 13, 3);
    } catch (Date::Bad_Date) {
        cerr << "Bad Date Error";
    }

    return 0;
}

