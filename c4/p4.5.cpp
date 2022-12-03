#include<iostream>
#include<limits>

using namespace std;

int main()
{
    cout << "char : max : " << (int)numeric_limits<char>::max() << endl
            <<"       min : "<<(int)numeric_limits<char>::min()<< endl << endl;
    cout << "short : max : " << numeric_limits<short>::max() << endl
            <<"        min : "<<numeric_limits<short>::min() << endl << endl;
    cout << "int : max : " << numeric_limits<int>::max() << endl
            <<"      min : "<<numeric_limits<int>::min() << endl << endl;
    cout << "long : max : " << numeric_limits<long>::max() << endl
            <<"       min : "<<numeric_limits<long>::min() << endl << endl;
    cout << "float : max : " << numeric_limits<float>::max() << endl
            <<"        min : "<<numeric_limits<float>::lowest() << endl << endl;
    cout << "double : max : " << numeric_limits<double>::max() << endl
            <<"         min : "<<numeric_limits<double>::lowest() << endl << endl;
    cout << "long double : max : " << numeric_limits<long double>::max() << endl
            <<"              min : "<<numeric_limits<long double>::min() << endl << endl;
    cout << "unsigned : max: " << numeric_limits<unsigned>::max() << endl
            <<"           min : "<<numeric_limits<unsigned>::min()<< endl << endl;

    return 0;
}
