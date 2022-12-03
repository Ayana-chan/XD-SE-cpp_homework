#include <iostream>
#include <string>

using namespace std;

#define STR_MAX_SIZE 1000

//1
void findInStr()
{
    //get a pair of letters
    char aim[2];
    cout << "Aim Char :";
    cin >> aim;
    //get the string
    string s;
    cout << "String :";
    cin >> s;
    //search
    int cnt = 0;
    for(string::const_iterator i = s.begin(); i + 1 != s.end(); i++)//traverse
    {
        if (*i == aim[0] && *(i + 1) == aim[1]) {//No.i and No.(i+1) need to fit at the same time
            cnt++;
        }
    }
    cout << "Answer:" << cnt << endl;
}
//2
void findInCArray()
{
    //get a pair of letters
    char aim[2];
    cout << "Aim Char :";
    cin >> aim;
    //get the char array
    char s[STR_MAX_SIZE]={0};
    cout << "String :";
    cin >> s[0];
    for(int i=1 ; s[i-1]!='0' ; i++){
        cin >> s[i];
    }
    //search
    int cnt=0;
    for(int i=0 ; s[i]!=0 ; i++){
        if(s[i] == aim[0] && s[i + 1] == aim[1]) {
            cnt++;
        }
    }
    cout << "Answer:" << cnt << endl;
}

int main()
{
    cout << "Find In String:" << endl;
    findInStr();
    cout << endl;
    cout << "Find In Char Array:" << endl;
    findInCArray();

    return 0;
}
