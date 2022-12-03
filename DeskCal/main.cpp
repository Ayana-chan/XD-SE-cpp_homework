#include <sstream>

#include "parser.h"
#include "error.h"

using namespace Parser_Arithmometer;
using namespace Parser_BasicReader;
using namespace Error;

istream* input;

int main(int argc, char *argv[]) {
    switch (argc) {
        case 1: //read from standard input
            input=&cin;
            break;
        case 2: //read argument string
            input=new istringstream(argv[1]);
            break;
        default:
            error("too many arguments");
            return 1;//Only 1 error exactly.
    }
    //insert predefined names
    table["pi"] = 3.1415926535897932385;
    table["e"]  = 2.7182818284590452354;

    while(*input){//stop when input error
        get_token();
        if(curr_tok == END)
            break;
        if(curr_tok != PRINT)
            cout << expr(false) << '\n';//calculate
    }

    if(input!=&cin)
        delete input;

//    system("pause");//Add this command if necessary.
    return no_of_errors;//show the number of errors
}
