#include<iostream>

using namespace std;

class Date {
    int d, m, y;
    const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int offset[12] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool is_leap_year(int y) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)return true;
        return false;
    }

public:
    Date(int dd, int mm, int yy) {
        if (mm <= 0 || mm > 12 || dd <= 0 || (!is_leap_year(yy) && dd > day[mm]) ||
            (is_leap_year(yy) && dd > day[mm] + offset[mm])) {
            std::cout << "日期初始化异常，重置为1970.1.1" << '\n';
            d = 1;
            m = 1;
            y = 1970;
        } else {
            d = dd;
            m = mm;
            y = yy;
        }
    }

    int calculate() {
        int count = 0;
        for (int i = 1970; i < y; i++) {
            if (is_leap_year(i)) {
                count += 366;
            } else count += 365;
        }
        for (int i = 1; i < m; i++) {
            if (!is_leap_year(i)) {
                count += day[i - 1];
            } else count += day[i - 1] + offset[i - 1];
        }
        count = count + d - 1;
        return count;
    }

    void print() {
        cout << "d,m,y: " << d << "," << m << "," << y
             << "  dayNum: " << calculate() << endl;
    }
};

int main(){
	Date test1(1,2,1970);
	test1.print();
    Date test2(1,2,1971);
    test2.print();
    Date test3(1,2,1972);
    test3.print();
    Date test4(1,2,1973);
    test4.print();
	return 0;
}
