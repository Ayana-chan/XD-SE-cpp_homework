#include <iostream>
#include <sstream>
#include <cstdarg>

using namespace std;

void error(string s, ...)//unlimited argument
{
    istringstream inStr(s);
    char ch;
    va_list args;
    va_start(args, s);
    //va_arg(arg,next arg type);

    while (inStr.get(ch)){
        if(ch=='%'){
            switch(inStr.peek()){//"%?"
            case 's':
                cout << va_arg(args,char*);
                inStr.get();
                break;
            case 'c':
                cout << (char)(va_arg(args, int));
//              cout << va_arg(args, char);//failed
//              this va_arg has undefined behavior because arguments will be promoted to 'int'
                inStr.get();
                break;
            case 'd':
                cout << va_arg(args,int);
                inStr.get();
                break;
            case '%'://necessary
                cout << (char)inStr.get();//eat '%'
                break;
            default:
                cout << ch;
                break;
            }
        }
        else
            cout << ch;
    }
    cout << endl;//'\n' doesn't be requested.
    va_end(args);
}

int main()
{
    error("testS1:%d%c%s%%dy5", 114,'G',"dog");
}
