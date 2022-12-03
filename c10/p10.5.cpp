#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>

using namespace std;

class Histogram
{
private:
    //bounds
    int smallestBound;
    int biggestBound;
    map<int,int> boundsMap;//First int:bound values. Second int:counter

public:
    Histogram(set<int>& inBounds);
    //add
    void add(int value);
    void addAll(const list<int>& valueList);//add all number in the set
    //print
    void printHis();
    //error
    class OutOfRangeError {
    public:
        string errorContent="OutOfRangeError";
    };
    class TooLittleBoundsError {
    public:
        string errorContent="TooLittleBoundsError";
    };
};

Histogram::Histogram(std::set<int>& inBounds)//sorted
{
    if(inBounds.size() <= 1)
        throw TooLittleBoundsError();

    set<int>::const_iterator i;
    for(i = inBounds.begin(); i != inBounds.end(); i++){
        boundsMap.insert(std::pair<int,int>(*i, 0));
        biggestBound = *i;
    }
    boundsMap.erase(biggestBound);//last bound doesn't needed.
    smallestBound = *(inBounds.begin());
}

void Histogram::add(int value)
{
    if(value < smallestBound || value > biggestBound)
        throw OutOfRangeError();

    map<int,int>::iterator i = boundsMap.upper_bound(value);
    i--;//make value at the right of i. If equals to biggestBound,then belongs to the last interval.
    i->second++;//count++
}

void Histogram::addAll(const list<int>& valueList) {
    for (int i : valueList) {
        try {
            add(i);
        } catch (OutOfRangeError &e) {
            cerr << e.errorContent << " : Value out of range." << endl;
        }
    }
}

void Histogram::printHis()
{
    cout << "Histogram:" << endl;
    for(map<int,int>::const_iterator i = boundsMap.begin(); i != boundsMap.end(); i++){
        map<int,int>::const_iterator nexti = i;
        nexti++;
        bool preEndFlag= nexti==boundsMap.end();//weather next is end
        cout << "[ ";
        //left bound
        cout.width(4);
        cout << i->first;
        //
        cout.width(0);
        cout << " , ";
        //
        if(preEndFlag) {
            //right bound
            cout.width(4);
            cout << biggestBound;
            cout.width(0);
            cout << " ]";
        }else {
            //right bound
            cout.width(4);
            cout << nexti->first;
            //
            cout.width(0);
            cout << " )";
        }
        //graph
        cout << "->|" << string(i->second,'#');
        cout << " " << i->second << std::endl;
    }
}

int main()
{
    try {
        set<int> inBounds = {0, 10, 20, 30, 46, 50, 60, 69, 80, 90, 100};
        list<int> valueList = {-1,0, 100, 96, 96,2, 1, 15, 16, 37, 10, 24, 35, 32, 12, 5, 78, 45, 78};
        Histogram hist(inBounds);

        hist.addAll(valueList);
        hist.printHis();
    }
    catch(Histogram::OutOfRangeError& e)
    {
        cerr << e.errorContent << " : Value out of range." << endl;
    }
    catch(Histogram::TooLittleBoundsError& e)
    {
        cerr << e.errorContent << " : Two or more bounds required." << endl;
    }

    return 0;
}
