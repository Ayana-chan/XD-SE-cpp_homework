#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    string s;
    vector<string> inWords;//entre order
    set<string> outWords;//sorted order

    while(true){
        cin >> s;//be divided only by space,need to be improved
        if(s != "Quit"){
            if (outWords.insert(s).second){//use 'set' to kill repeat and sort
                inWords.push_back(s);//use 'second' to judge repeat to keep entre information
            }
        } else{
            break;//reading finished
        }
    }

    cout << "enter:" << endl;
    for(const auto & inWord : inWords)
    {
        cout << "   " << inWord << endl;
    }

    cout << endl << "sorted: " << endl;
    for(const auto & outWord : outWords)
    {
        cout << "   " << outWord << endl;
    }
}
